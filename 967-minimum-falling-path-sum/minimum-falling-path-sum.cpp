class Solution {
public:

    // int dp[101][101];

    // int TD(int i, int j, int &n, int& m, vector<vector<int>>& mat){
    //     if(i >= n || j >= m || j < 0) return INT_MAX;
    //     if(i == n-1){
    //         return mat[i][j];
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     dp[i][j] = mat[i][j] + min(TD(i+1, j-1, n, m, mat), min(TD(i+1, j, n, m, mat), TD(i+1, j+1, n, m, mat)));
    //     return dp[i][j];
    // }

    int BU(int n, int m, vector<vector<int>>& mat){
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n-1] = mat[n-1];
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<m; j++){
                int left = INT_MAX, right = INT_MAX, mid = dp[i+1][j];
                if(j-1 >= 0){
                    left = dp[i+1][j-1];
                }
                if(j+1 < m){
                    right = dp[i+1][j+1];
                }
                dp[i][j] = mat[i][j] + min(left, min(mid, right));
            }
        }
        int mini = INT_MAX;
        for(int i=0; i<m; i++){
            mini = min(mini, dp[0][i]);
        }
        return mini;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // int mini = INT_MAX;
        // memset(dp, -1, sizeof(dp));
        // for(int i=0; i<m; i++){
        //     mini = min(mini, TD(0, i, n, m, matrix));
        // }
        // return mini;
        return BU(n, m, matrix);
    }
};