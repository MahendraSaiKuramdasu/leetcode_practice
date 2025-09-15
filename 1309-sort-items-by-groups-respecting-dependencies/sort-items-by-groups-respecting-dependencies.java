class Solution {
    private ArrayList<Integer> topo_sort(HashMap<Integer,ArrayList<Integer>> adj, ArrayList<Integer> deg, int n){
        Queue<Integer> q = new LinkedList<>();
        for(int i=0; i<n; i++){
            if(deg.get(i) == 0){
                q.add(i);
            }
        }
        ArrayList<Integer> res = new ArrayList<>();
        while(!q.isEmpty()){
            int lem = q.size();
            while(lem-- > 0){
                int node = q.poll();
                res.add(node);
                for(int i=0; adj.containsKey(node) && i<adj.get(node).size(); i++){
                    int nei = adj.get(node).get(i);
                    deg.set(nei, deg.get(nei) - 1);
                    if(deg.get(adj.get(node).get(i)) == 0){
                        q.add(adj.get(node).get(i));
                    }
                }
            }
        }
        return res;
    }
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> bi) {
        // items adj list
        HashMap<Integer,ArrayList<Integer>> i_adj = new HashMap<>();
        ArrayList<Integer> i_deg = new ArrayList<>();
        for(int i=0; i<n; i++){
            i_deg.add(0);
        }
        for(int i=0; i<n; i++){
            int lem = bi.get(i).size();
            for(int j=0; j<lem; j++){
                int u = bi.get(i).get(j);
                int v = i;
                if(i_adj.containsKey(u)){
                    i_adj.get(u).add(v);
                }
                else{
                    i_adj.put(u, new ArrayList<>());
                    i_adj.get(u).add(v);
                }
                i_deg.set(v, i_deg.get(v)+1);
            }
        }
        // groups adj list
        HashMap<Integer,ArrayList<Integer>> g_adj = new HashMap<>();
        ArrayList<Integer> g_deg = new ArrayList<>();
        HashMap<Integer, ArrayList<Integer>> mapping = new HashMap<>();
        int cnt = m;
        for(int i=0; i<n; i++){
            if(group[i] == -1){
                group[i] = cnt++;
            }
            // if(mapping.containsKey(group[i])){
            //     mapping.get(group[i]).add(i);
            // }
            // else{
            //     mapping.put(group[i], new ArrayList<>());
            //     mapping.get(group[i]).add(i);
            // }
        }
        for(int i=0; i<cnt; i++){
            g_deg.add(0);
        }
        for(int i=0; i<n; i++){
            int lem = bi.get(i).size();
            for(int j=0; j<lem; j++){
                int v_item = i;
                int u_item = bi.get(i).get(j);
                int v = group[v_item];
                int u = group[u_item];
                if(u != v){
                    if(g_adj.containsKey(u)){
                        g_adj.get(u).add(v);
                    }
                    else{
                        g_adj.put(u, new ArrayList<>());
                        g_adj.get(u).add(v);
                    }
                    g_deg.set(v, g_deg.get(v)+1);
                }
            }
        }
        ArrayList<Integer> items_topo = topo_sort(i_adj, i_deg, n);
        ArrayList<Integer> groups_topo = topo_sort(g_adj, g_deg, cnt);
        ArrayList<Integer> ans = new ArrayList<>();
        if(items_topo.size() != n || groups_topo.size() != cnt){
            return new int[0];
        }
        for(int i=0; i<n; i++){
            int curr = items_topo.get(i);
            int curr_group = group[curr];
            if(!mapping.containsKey(curr_group)){
                mapping.put(curr_group, new ArrayList<>());
            }
            mapping.get(curr_group).add(curr);
        }
        for(int i=0; i<groups_topo.size(); i++){
            int curr = groups_topo.get(i);
            for(int j=0; mapping.containsKey(curr) && j<mapping.get(curr).size(); j++){
                ans.add(mapping.get(curr).get(j));
            }
        }
        // for(int i=0; i<n; i++){
        //     System.out.print(ans.get(i));
        // }
        int[] res = ans.stream().mapToInt(i -> i).toArray();
        return res;
    }
}