class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n == 0) {
            return new ArrayList<>();
        }
        if (n == 1) {
            return List.of(0);
        }
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<n; i++){
            adj.add(new ArrayList<>());
        }
        int [] indeg = new int[n];
        for(int i=0; i<n; i++){
            indeg[i] = 0;
        }
        for(int i=0; i<edges.length; i++){
            Integer u = edges[i][0];
            Integer v = edges[i][1];
            adj.get(u).add(v);
            adj.get(v).add(u);
            indeg[u]++;
            indeg[v]++;
        }
        Queue<Integer> q = new LinkedList<>();
        List<Integer> res = new ArrayList<>();
        // int [] vis = new int[n];
        // for(int i=0; i<n; i++){
        //     vis[i] = 0;
        // }
        for(int i=0; i<n; i++){
            if(indeg[i] == 1){
                q.add(i);
                // vis[i] = 1;
            }
        }
        while(!q.isEmpty()){
            List<Integer> temp = new ArrayList<>();
            int tempN = q.size();
            while(tempN-- != 0){
                int node = q.peek();
                q.remove();
                temp.add(node);
                for(int j=0; j<adj.get(node).size(); j++){
                    // if(vis[adj.get(node).get(j)] == 0){
                    //     q.add(adj.get(node).get(j));
                    //     vis[adj.get(node).get(j)] = 1;
                    // }
                    indeg[adj.get(node).get(j)]--;
                    if(indeg[adj.get(node).get(j)] == 1){
                        q.add(adj.get(node).get(j));
                    }
                }
            }
            res = temp;
        }
        return res;
    }
}