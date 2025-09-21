class Solution {

    private class edge{
        int u;
        int x;
        edge(int u, int x){
            this.x = x;
            this.u = u;
        }
    }

    private class pqedge{
        int u;
        int x;
        int k;
        pqedge(int u, int x, int k){
            this.u = u;
            this.x = x;
            this.k = k;
        }
    }

    public int findCheapestPrice(int n, int[][] edges, int src, int dst, int k) {
        // adj list init
        ArrayList<ArrayList<edge>> adj = new ArrayList<>();
        ArrayList<ArrayList<Integer>> dist = new ArrayList<>();
        for(int i=0; i<n; i++){
            adj.add(new ArrayList<>());
            dist.add(new ArrayList<>());
            for(int j=0; j<k+1; j++){
                dist.get(i).add(Integer.MAX_VALUE);
            }
        }
        // fill adj list
        for(int i=0; i<edges.length; i++){
            adj.get(edges[i][0]).add(new edge(edges[i][1], edges[i][2]));
        }
        PriorityQueue<pqedge> pq = new PriorityQueue<>(
            (a, b) -> Integer.compare(a.x, b.x)
        );
        pq.add(new pqedge(src, 0, 0));
        while(!pq.isEmpty()){
            int node = pq.peek().u;
            System.out.print(node + " ");
            int d = pq.peek().x;
            int ktime = pq.peek().k;
            pq.poll();
            for(edge nei : adj.get(node)){
                if(ktime <= k && dist.get(nei.u).get(ktime) > (d + nei.x)){
                    dist.get(nei.u).set(ktime, (d + nei.x));
                    pq.add(new pqedge(nei.u, d + nei.x, ktime + 1));
                }
            }
        }
        int best_dis = Integer.MAX_VALUE;
        for(int i=0; i<=k; i++){
            best_dis = Math.min(dist.get(dst).get(i), best_dis);
        }
        if(best_dis == Integer.MAX_VALUE){
            return -1;
        }
        return best_dis;
    }
}