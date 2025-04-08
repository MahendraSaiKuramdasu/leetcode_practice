class Solution {
public:

    int TD(int i, bool status, int n, vector<int>& prices){
        if(i >= n) return 0;
        int ans = 0;
        if(status){
            ans = max(prices[i] + TD(i+2, 0, n, prices), TD(i+1, 1, n, prices));
        }
        else{
            ans = max(-prices[i] + TD(i+1, 1, n, prices), TD(i+1, 0, n, prices));
        }
        return ans;
    }

    int BU(int n, vector<int>& prices){
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                if(j){
                    dp[i][j] = max(prices[i] + dp[i+2][0], dp[i+1][1]);
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
        // return TD(0, 0, n, prices);
        return BU(n, prices);
    }
};