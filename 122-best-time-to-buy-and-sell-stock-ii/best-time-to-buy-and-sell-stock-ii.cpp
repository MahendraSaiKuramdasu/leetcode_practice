class Solution {
public:

    // int dp[30001][2];

    // int TD(int i, bool stock, int n, vector<int>& prices){
    //     if(i == n) return 0;
    //     if(dp[i][stock] != -1) return dp[i][stock];
    //     int ans = 0;
    //     if(stock){
    //         ans = max(prices[i] + TD(i+1, 0, n, prices), TD(i+1, 1, n, prices));
    //     }
    //     else{
    //         ans = max(-prices[i] + TD(i+1, 1, n, prices), TD(i+1, 0, n, prices));
    //     }
    //     return dp[i][stock] = ans;
    // }

    int BU(int n, vector<int>& prices){
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                if(j == 1){
                    dp[i][j] = max(prices[i] + dp[i+1][0], dp[i+1][1]);
                }
                else{
                    dp[i][j] = max(-prices[i] + dp[i+1][1], dp[i+1][0]);
                }
            }
        }
        return dp[0][0];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // memset(dp, -1, sizeof(dp));
        // int ans = TD(0, 0, n, prices);
        int ans = BU(n, prices); 
        return ans;
    }
};