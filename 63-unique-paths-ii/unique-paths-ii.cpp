class Solution {
public:

    int dp[101][101];

    int TD(int i, int j, int& n, int& m, vector<vector<int>>& grid){
        if(i >= n || j>= m || grid[i][j] == 1) return 0;
        if(i == n-1 && j == m-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = TD(i+1, j, n, m, grid) + TD(i, j+1, n, m, grid);
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return TD(0, 0, n, m, grid);
    }
};