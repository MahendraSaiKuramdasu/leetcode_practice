class Solution {
    private Integer findPath(ArrayList<Integer> par, int x){
        if(par.get(x) == x){
            return x;
        }
        // rec + path compression
        par.set(x, findPath(par, par.get(x)));
        return par.get(x);
    }
    // DSU algo for combining both cities
    private void DSU(int a, int b, ArrayList<Integer> par, ArrayList<Integer> rank){
        int par_a = findPath(par, a);
        int par_b = findPath(par, b);
        if(rank.get(par_a) >= rank.get(par_b)){
            rank.set(par_a, rank.get(par_a)+1);
            rank.set(par_b, 0);
            par.set(par_b, par_a);
        }
        else{
            rank.set(par_b, rank.get(par_b)+1);
            rank.set(par_a, 0);
            par.set(par_a, par_b);
        }
    }
    // given
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        ArrayList<Integer> rank = new ArrayList<>();
        ArrayList<Integer> par = new ArrayList<>();
        for(int i=0; i<n+1; i++){
            rank.add(0);
            par.add(i);
            if(i == 0){
                par.set(i, -1);
            }
        }
        int[] ans = new int[2];
        for(int i=0; i<n; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int par_a = findPath(par, a);
            int par_b = findPath(par, b);
            if(par_a == par_b){
                ans[0] = a;
                ans[1] = b;
                break;
            }
            DSU(a, b, par, rank);
        }
        return ans;
    }
}