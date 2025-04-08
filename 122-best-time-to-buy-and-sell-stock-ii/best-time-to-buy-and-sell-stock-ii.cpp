class Solution {
public:

    int dp[30001][2];

    int TD(int i, bool stock, int n, vector<int>& prices){
        if(i == n) return 0;
        if(dp[i][stock] != -1) return dp[i][stock];
        int ans = 0;
        if(stock){
            ans = max(prices[i] + TD(i+1, 0, n, prices), TD(i+1, 1, n, prices));
        }
        else{
            ans = max(-prices[i] + TD(i+1, 1, n, prices), TD(i+1, 0, n, prices));
        }
        return dp[i][stock] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        int ans = TD(0, 0, n, prices);
        return ans;
    }
};