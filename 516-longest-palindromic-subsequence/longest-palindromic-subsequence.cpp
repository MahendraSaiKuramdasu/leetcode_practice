class Solution {
public:

    int TD(int i, int j, string& str){
        if(i == j){
            return 1;
        }
        if(i > j){
            return 0;
        }
        int ans = 0;
        if(str[i] == str[j]){
            ans = 2 + TD(i+1, j-1, str);
        }
        else{
            ans = max(TD(i+1, j, str), TD(i, j-1, str));  
        }
        return ans;
    }

    int BU(int n, string& str){
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                if(i > j) continue;
                if(i == j){
                    dp[i][j] = 1;
                    continue;
                }
                if(str[i] == str[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        // int ans = TD(0, n-1, s);
        int ans = BU(n, s);
        return ans;
    }
};