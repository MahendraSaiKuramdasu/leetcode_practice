class Solution {
public:

    // int TD(int n, int m, string& w1, string& w2){
    //     if(n < 0 && m < 0){
    //         return 0;
    //     }
    //     if(n < 0){
    //         return m+1;
    //     }
    //     if(m < 0){
    //         return n+1;
    //     }
    //     int ans = INT_MAX;
    //     if(w1[n] == w2[m]){
    //         ans = 0 + TD(n-1, m-1, w1, w2);
    //     }
    //     else{
    //         // insert
    //         ans = 1 + TD(n, m-1, w1, w2); 
    //         // delete
    //         ans = min(ans, 1 + TD(n-1, m, w1, w2));
    //         // replace
    //         ans = min(ans, 1 + TD(n-1, m-1, w1, w2));
    //     }
    //     return ans;
    // }

    int BU(int n, int m, string& w1, string& w2){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            dp[i][0] = i;
        }
        for(int i=1; i<=m; i++){
            dp[0][i] = i;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(w1[i-1] == w2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + dp[i-1][j];
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j-1]);
                    dp[i][j] = min(dp[i][j], 1 + dp[i-1][j-1]);
                }
            }
        }
        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        // int mini = TD(n-1, m-1, word1, word2);
        int mini = BU(n, m, word1, word2);
        return mini;
    }
};