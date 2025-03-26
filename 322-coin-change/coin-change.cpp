#define ll long long

class Solution {
public:

    // ll TD(int amount, vector<int>& coins, int& n, vector<ll>& dp){
    //     if(amount < 0) return INT_MAX;
    //     if(amount == 0) return 0;
    //     if(dp[amount] != )
    //     ll mini = INT_MAX;
    //     for(int i=0; i<n; i++){
    //         mini = min(mini, 1+TD(amount - coins[i], coins, n, dp));
    //     }
    //     return mini;
    // }

    int BU(int amount, int n, vector<int>& coins){
        vector<ll> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<n; j++){
                if(i - coins[j] >= 0){
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                }
            }
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = BU(amount, n, coins);
        if(ans > 1e4){
            ans = -1;
        }
        return ans;
    }
};