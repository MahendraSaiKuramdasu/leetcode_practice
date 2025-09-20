class Solution {

    private class node{
        int v;
        int dis;
        node(int v, int d){
            this.v = v;
            this.dis = d;
        }
    }

    public int networkDelayTime(int[][] times, int n, int k) {
        // time to reach from the source node
        ArrayList<Integer> time = new ArrayList<>();
        // make adj list
        ArrayList<ArrayList<node>> adj = new ArrayList<>();
        for(int i=0; i<n+1; i++){
            time.add(Integer.MAX_VALUE);
            adj.add(new ArrayList<>());
        }
        // fill adj array
        for(int i=0; i<times.length; i++){
            int u = times[i][0];
            int v = times[i][1];
            int d = times[i][2];
            node temp = new node(v, d);
            adj.get(u).add(temp);
        }
        // make a heap for dijkstra algo
        PriorityQueue<node> pq = new PriorityQueue<>(
            (a, b) -> Integer.compare(a.dis, b.dis)
        );
        // push to queue
        pq.add(new node(k, 0));
        while(!pq.isEmpty()){
            int nod = pq.peek().v;
            int dis = pq.peek().dis;
            pq.poll();
            if(dis < time.get(nod)){
                time.set(nod, dis);
                for(node nib : adj.get(nod)){
                    int n_v = nib.v;
                    int n_dis = nib.dis + dis;
                    pq.add(new node(n_v, n_dis));
                }
            }
        }
        int max_time = -1;
        for(int i=1; i<n+1; i++){
            if(time.get(i) == Integer.MAX_VALUE){
                return -1;
            }
            max_time = Math.max(max_time, time.get(i));
        }
        return max_time;
    }
}