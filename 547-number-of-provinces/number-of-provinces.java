class Solution {
    // find path Algorithm
    // set of lines of code
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
    public int findCircleNum(int[][] adj) {
        // based on 1 based index
        int n = adj.length;
        // rank array
        ArrayList<Integer> rank = new ArrayList<>();
        // fill rank array
        for(int i=0; i<n+1; i++){
            rank.add(0);
        }
        // parent array
        ArrayList<Integer> par = new ArrayList<>();
        // fill parent array
        for(int i=0; i<n+1; i++){
            par.add(i);
            if(i == 0){
                par.set(i, -1);
            }
        }
        // adj list travel
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && adj[i][j] == 1){
                    // merging
                    DSU(i+1, j+1, par, rank);
                }
            }
        }
        Integer ans = 0;
        // finding provinces if par[i] == i
        for(int i=0; i<n+1; i++){
            if(i == par.get(i)){
                ans++;
            }
        }
        // System.out.print(par);
        // System.out.println(rank);
        return ans;
    }
}