class Solution {

    private static final int[][] dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
 
    private class cell{
        int i;
        int j;
        int abs;
        cell(int i, int j, int abs){
            this.i = i;
            this.j = j;
            this.abs = abs;
        }
    } 

    public int minimumEffortPath(int[][] heights) {
        int n = heights.length;
        int m = heights[0].length;
        int[][] res = new int[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                res[i][j] = Integer.MAX_VALUE;
            }
        }
        res[0][0] = 0;
        PriorityQueue<cell> pq = new PriorityQueue<>(
            (a, b) -> Integer.compare(a.abs, b.abs)
        );
        pq.add(new cell(0, 0, 0));
        while(!pq.isEmpty()){
            int i = pq.peek().i;
            int j = pq.peek().j;
            int abs = pq.peek().abs;
            int val = heights[i][j];
            pq.poll();
            for(int d=0; d<4; d++){
                int x = i + dir[d][0];
                int y = j + dir[d][1];
                if(x >= 0 && y >= 0 && x < n && y < m){
                    int curr_abs = Math.max(abs, Math.abs(val - heights[x][y]));
                    if(res[x][y] > curr_abs){
                        res[x][y] = curr_abs;
                        if(x != n-1 || y != m-1){
                            pq.add(new cell(x, y, curr_abs));
                        }
                    }
                }
            }
        }
        return res[n-1][m-1];
    }
}