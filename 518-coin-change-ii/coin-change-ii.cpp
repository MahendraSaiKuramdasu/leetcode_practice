#define ll long long
int mod = 1e11+7 ;

class Solution {
public:

    // int TD(int n, int tar, vector<int>& coins, vector<vector<int>>& dp){
        // if(n == 0){
        //     if(tar%coins[0] == 0){
        //         return 1;
        //     }
        //     return 0;
        // }
    //     if(tar < 0) return 0;
    //     if(tar == 0){
    //         return 1;
    //     }
    //     if(dp[n][tar] != -1){
    //         return dp[n][tar];
    //     }
    //     int exclude = TD(n-1, tar, coins, dp);
    //     int include = 0;
    //     if(tar - coins[n] >= 0){
    //         include = TD(n, tar-coins[n], coins, dp);
    //     }
    //     dp[n][tar] = include + exclude;
    //     return dp[n][tar];
    // }

    int BU(int n, int tar, vector<int>& coins){
        // vector<vector<ll>> dp(n, vector<ll>(tar+1, 0));
        if(n == 1) return tar%coins[0] == 0;
        vector<ll> pre(tar+1, 0);
        vector<ll> curr(tar+1, 0);
        curr[0] = 1;
        pre[0] = 1;
        // for(int i=0; i<n; i++){
        //     dp[i][0] = 1;
        // }
        for(int i=1; i<=tar; i++){
            if(i%coins[0] == 0){
                // dp[0][i] = 1;
                pre[i] = 1;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<=tar; j++){
                // ll exclude = dp[i-1][j];
                ll exclude = pre[j];
                ll include = 0;
                if(j - coins[i] >= 0){
                    // include = dp[i][j-coins[i]];
                    include = curr[j-coins[i]];
                }
                curr[j] = (include + exclude)%mod;
            }
            pre = curr;
        }
        return curr[tar];
    }

    int change(int amount, vector<int>& coins) {
        // vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        // return TD(coins.size()-1, amount, coins, dp);
        return BU(coins.size(), amount, coins);
    }
};