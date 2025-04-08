class Solution {
public:

    int BU(int fee, int& n, vector<int>& prices){
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                if(j){
                    dp[i][j] = max((prices[i] - fee) + dp[i+1][0], dp[i+1][1]);
                }
                else{
                    dp[i][j] = max(-prices[i] + dp[i+1][1], dp[i+1][0]);
                }
            }
        }
        return dp[0][0];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        return BU(fee, n, prices);
    }
};