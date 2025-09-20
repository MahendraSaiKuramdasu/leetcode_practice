class Solution {

    private class edge{
        int dis;
        int a; 
        int b;
        int index;
        edge(int dis, int a, int b, int i){
            this.dis = dis;
            this.a = a;
            this.b = b;
            this.index = i;
        }
    }

    private int findPar(ArrayList<Integer> par, int x){
        if(x == par.get(x)){
            return x;
        }
        par.set(x, findPar(par, par.get(x)));
        return par.get(x);
    }

    // DSU method
    private void DSU(int a, int b, ArrayList<Integer> par, ArrayList<Integer> rank){
        int par_a = findPar(par, a);
        int par_b = findPar(par, b);
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

    private int kruskal(int n, int[][] edges, int indexCheck, int addEdge){
        // min heap for picking min edges
        PriorityQueue<edge> min_heap = new PriorityQueue<>(
            (a, b) -> Integer.compare(a.dis, b.dis)
        );
        int mst = 0;
        ArrayList<Integer> par = new ArrayList<>();
        ArrayList<Integer> rank = new ArrayList<>();
        // fill parent and rank array
        for(int i=0; i<n; i++){
            par.add(i);
            rank.add(1);
        }
        // add to min heap
        for(int i=0; i<edges.length; i++){
            if(addEdge == i){
                DSU(edges[i][0], edges[i][1], par, rank);
                mst += edges[i][2];
                continue;
            }
            edge temp = new edge(edges[i][2], edges[i][0], edges[i][1], i);
            min_heap.add(temp);
        }
        // selecting edges through MST
        while(!min_heap.isEmpty()){
            edge curr = min_heap.poll();
            int par_a = findPar(par, curr.a);
            int par_b = findPar(par, curr.b);
            if(par_a != par_b && indexCheck != curr.index){
                DSU(curr.a, curr.b, par, rank);
                mst += curr.dis;
            }
        }
        for(int i=0; i<n; i++){
            if(findPar(par, i) != findPar(par, 0)){
                return Integer.MAX_VALUE;
            }
        }
        return mst;
    }

    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
        List<Integer> critical = new ArrayList<>();
        List<Integer> pcritical = new ArrayList<>();
        int mst = kruskal(n, edges, -1, -1);
        for(int i=0; i<edges.length; i++){
            if(mst < kruskal(n, edges, i, -1)){
                critical.add(i);
            }
            else if(mst == kruskal(n, edges, -1, i)){
                pcritical.add(i);
            }
        }
        List<List<Integer>> ans = new ArrayList<>(List.of(critical, pcritical));
        System.out.print(mst);
        return ans;
    }
}