class Solution {

    private class edge{
        int node;
        double p;
        edge(int u, double p){
            this.node = u;
            this.p = p;
        }
    }

    public double maxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node) {
        ArrayList<ArrayList<edge>> graph = new ArrayList<>();
        ArrayList<Double> dis = new ArrayList<>();
        for(int i=0; i<n; i++){
            dis.add(Double.valueOf(0));
            graph.add(new ArrayList<>());
        }
        for(int e=0; e<edges.length; e++){
            int u = edges[e][0];
            int v = edges[e][1];
            double pro = succProb[e];
            graph.get(u).add(new edge(v, pro));
            graph.get(v).add(new edge(u, pro));
        }
        if(graph.get(end_node).size() == 0){
            return 0.0;
        }
        dis.set(start_node, 1.0);
        PriorityQueue<edge> pq = new PriorityQueue<>(
            (a, b) -> Double.compare(b.p, a.p)
        );
        pq.add(new edge(start_node, 1));
        while(!pq.isEmpty()){
            int node = pq.peek().node;
            double pro = pq.peek().p;
            pq.poll();
            for(edge e : graph.get(node)){
                if(dis.get(e.node) < (pro * e.p)){
                    pq.add(new edge(e.node, pro * e.p));
                    dis.set(e.node, (pro * e.p));
                }
            }
        }
        return dis.get(end_node);
    }
}