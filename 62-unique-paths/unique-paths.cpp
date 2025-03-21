class Solution {
public:

    int dp[101][101];

    bool outOfBound(int i, int j, int n, int m){
        if(i >= n || j >= m) return true;
        return false;
    }

    int TD(int i, int j, int n, int m){
        if(outOfBound(i, j, n, m)) return 0;
        if(i == n-1 && j == m-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = (TD(i+1, j, n, m) + TD(i, j+1, n, m));
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return TD(0, 0, m, n);
    }
};