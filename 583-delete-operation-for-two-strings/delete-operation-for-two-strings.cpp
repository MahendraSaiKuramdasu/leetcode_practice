class Solution {
public:

    int TD(int n, int m, string& s1, string& s2){
        if(n < 0 || m < 0){
            if(n < 0 && m < 0){
                return 0;
            }
            else if(n < 0){
                return m+1;
            }
            else{
                return n+1;
            }
        }
        int ans = 0;
        if(s1[n] == s2[m]){
            ans = TD(n-1, m-1, s1, s2);
        }
        else{
            ans = 1 + min(TD(n-1, m, s1, s2), TD(n, m-1, s1, s2));
        }
        return ans;
    }

    int BU(int n, int m, string& s1, string& s2){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            dp[i][0] = i;
        }
        for(int j=1; j<=m; j++){
            dp[0][j] = j;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        // int ans = TD(n-1, m-1, word1, word2);
        int ans = BU(n, m, word1, word2);
        return ans;
    }
};