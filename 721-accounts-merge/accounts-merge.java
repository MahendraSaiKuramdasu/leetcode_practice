class Solution {

    private boolean emailsMatch(int i, int j, HashMap<Integer, TreeSet<String>> adj){
        for(String x : adj.get(j)){
            if(adj.get(i).contains(x)){
                return true;
            }
        }
        return false;
    }

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

    public List<List<String>> accountsMerge(List<List<String>> acc) {
        int n =  acc.size();
        // map for accounts
        HashMap<Integer, TreeSet<String>> adj = new HashMap<>();
        // fill map
        for(int i=0; i<n; i++){
            // String name = acc.get(i).get(0);
            adj.put(i, new TreeSet<>());
            for(int j=1; j<acc.get(i).size(); j++){
                adj.get(i).add(acc.get(i).get(j));
                // index, emails
            }
        }
        // rank and par
        ArrayList<Integer> rank = new ArrayList<>();
        ArrayList<Integer> par = new ArrayList<>();
        for(int i=0; i<n; i++){
            rank.add(0);
            par.add(i);
        }
        // logic to merge
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(acc.get(i).get(0).equals(acc.get(j).get(0))){
                    // try if emails are matching are not
                    if(emailsMatch(i, j, adj)){
                        DSU(i, j, par, rank);
                        // break;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            if(par.get(i) != i){
                int par_i = findPath(par, i);
                for(String str : adj.get(i)){
                    adj.get(par_i).add(str);
                }
            }
        }
        List<List<String>> ans = new ArrayList<>();
        int index = 0;
        for(int i=0; i<n; i++){
            if(par.get(i) == i){
                ans.add(new ArrayList<>());
                ans.get(index).add(acc.get(i).get(0));
                // iterate treeset
                for(String x : adj.get(i)){
                    ans.get(index).add(x);
                }
                index++;
            }
        }
        return ans;
    }
}