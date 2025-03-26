class Solution {
public:

    int TD(int n, int tar, vector<int>& coins, vector<vector<int>>& dp){
        if(n < 0) return 0;
        if(tar < 0) return 0;
        if(tar == 0){
            return 1;
        }
        if(dp[n][tar] != -1){
            return dp[n][tar];
        }
        int exclude = TD(n-1, tar, coins, dp);
        int include = 0;
        if(tar - coins[n] >= 0){
            include = TD(n, tar-coins[n], coins, dp);
        }
        dp[n][tar] = include + exclude;
        return dp[n][tar];
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return TD(coins.size()-1, amount, coins, dp);
    }
};