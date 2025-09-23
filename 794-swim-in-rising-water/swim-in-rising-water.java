class Solution {

    int[][] dir = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

    private class cell{
        int i;
        int j;
        int time;
        cell(int i, int j, int t){
            this.i = i;
            this.j = j;
            this.time = t;
        }
    }

    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] res = new int[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                res[i][j] = Integer.MAX_VALUE;
            }
        }   
        res[0][0] = grid[0][0];
        int start_time = grid[0][0];
        PriorityQueue<cell> pq = new PriorityQueue<>(
            (a, b) -> Integer.compare(a.time, b.time)
        );
        pq.add(new cell(0, 0, start_time));
        while(!pq.isEmpty()){
            cell curr_cell = pq.poll();
            for(int d=0; d<4; d++){
                int x = curr_cell.i + dir[d][0];
                int y = curr_cell.j + dir[d][1];
                if(x >= 0 && y >= 0 && x < n && y < m){
                    int nei_time = grid[x][y];
                    int max_time = Math.max(nei_time, curr_cell.time);
                    if(max_time < res[x][y]){
                        res[x][y] = max_time;
                        pq.add(new cell(x, y, max_time));
                    }
                }
            }
        }
        return res[n-1][m-1];
    }
}