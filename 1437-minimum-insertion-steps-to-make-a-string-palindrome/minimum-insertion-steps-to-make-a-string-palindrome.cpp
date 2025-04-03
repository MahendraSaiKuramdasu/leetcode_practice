class Solution {
public:

    int TD(int i, int j, string& str){
        if(i>j){
            return 0;
        }
        int ans = 0;
        if(str[i] == str[j]){
            ans = TD(i+1, j-1, str);
        }
        else{
            ans = 1 + min(TD(i+1, j, str), TD(i, j-1, str));
        }
        return ans;
    }

    int BU(int n, string& str){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=n; j++){
                if(i>j-1) continue;
                if(str[i] == str[j-1]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j] = 1 + min( dp[i+1][j], dp[i][j-1] );
                }
            }
        }
        return dp[0][n];
    }

    int minInsertions(string s) {
        int n = s.length();
        // int ans = TD(0, n-1, s);
        int ans = BU(n, s);
        return ans;
    }
};