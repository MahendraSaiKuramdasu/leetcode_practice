class Solution {
public:

    // bool check(int m, string& p){
    //     for(int i=0; i<=m; i++){
    //         if(p[i] != '*'){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    bool TD(int n, int m, string& s, string& p){
        if(n < 0 && m < 0) return true;
        if(n < 0 && m >= 0){
            // if(check(m, p)){
            //     return true;
            // }
            if(m == 0 && p[m] == '*'){
                return true;
            }
            return false;
        }
        if(n >= 0 && m < 0) return false;
        bool ans = false;
        if(s[n] == p[m] || p[m] == '?'){
            ans = TD(n-1, m-1, s, p);
        }
        else if(p[m] == '*'){
            for(int k=n; k>=-1; k--){
                ans = TD(k, m-1, s, p);
                if(ans) return ans;
            }
        }
        return ans;
    }

    bool BU(int n, int m, string& s, string& p){
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        if(p[0] == '*'){
            dp[0][1] = true;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    for(int k=i; k>=0; k--){
                        dp[i][j] = dp[k][j-1];
                        if(dp[i][j]){
                            break;
                        }
                    }
                }
            }
        }
        return dp[n][m];
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        int cnt = 0;
        for(int i=0; i<m; i++){
            if(p[i] == '*'){
                cnt++;
            }
            else{
                break;
            }
        }
        if(cnt > 1){
            p = p.substr(cnt-1);
        }
        m = p.length();
        // bool ans = TD(n-1, m-1, s, p);
        bool ans= BU(n, m, s, p);
        return ans;
    }
};