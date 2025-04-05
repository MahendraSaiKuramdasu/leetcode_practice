#define ll long long   
int mod = 1e9+7; 
    
class Solution {
public:

    // int TD(int n, int m, string& s, string& t){
    //     if(m < 0){
    //         return 1;
    //     }
    //     if(n < 0){
    //         return 0;
    //     }
    //     int ans = INT_MIN;
    //     if(s[n] == t[m]){
    //         int way1 = TD(n-1, m-1, s, t);
    //         int way2 = TD(n-1, m, s, t);
    //         ans = way1 + way2;
    //     }
    //     else{
    //         ans = TD(n-1, m, s, t);
    //     }
    //     return ans;
    // }

    ll BU(int n, int m, string& s, string& t){
        vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m] % mod;
    }

    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n < m){
            return 0;
        }
        if(n == m){
            if(s == t) return 1;
            return 0;
        }
        // int ways = TD(n-1, m-1, s, t);
        ll ways = BU(n, m, s, t);
        return ways;
    }
};