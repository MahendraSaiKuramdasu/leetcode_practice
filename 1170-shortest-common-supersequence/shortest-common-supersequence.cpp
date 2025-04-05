class Solution {
public:

    // void giveLcs(string temp, string& ans, int n, int m, vector<vector<int>> dp, string& s1, string& s2){
    //     if(n == 0 || m == 0){
    //         ans = temp;
    //         return;
    //     }
    //     if(s1[n-1] == s2[m-1]){
    //         giveLcs(s1[n-1]+temp, ans, n-1, m-1, dp, s1, s2);
    //     }
    //     else{
    //         if(dp[n-1][m] >= dp[n][m-1]){
    //             giveLcs(temp, ans, n-1, m, dp, s1, s2);
    //         }
    //         else{
    //             giveLcs(temp, ans, n, m-1, dp, s1, s2);
    //         }
    //     }
    // }

    string buildSTR(int n, int m, vector<vector<int>>& dp, string& s1, string& s2){
        string ans = "";
        while(n != 0 && m != 0){
            if(s1[n-1] == s2[m-1]){
                ans = s1[n-1] + ans;
                --n;
                --m;
            }
            else{
                if(dp[n-1][m] >= dp[n][m-1]){
                    ans = s1[n-1] + ans;
                    --n;
                }
                else{
                    ans = s2[m-1] + ans;
                    --m;
                }
            }
        }
        while(n != 0){
            ans = s1[n-1] + ans;
            --n;
        }
        while(m != 0){
            ans = s2[m-1] + ans;
            --m;
        }
        return ans;
    }

    string BU(int n, int m, string& s1, string& s2){
        string ans = "";
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
                }
            }
        }
        // giveLcs("",ans,n, m, dp, s1, s2);
        ans = buildSTR(n, m, dp, s1, s2);
        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        string lcs = BU(n, m, str1, str2);
        return lcs;
    }
};