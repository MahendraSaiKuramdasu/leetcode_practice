class Solution {
public:

    int BU(int& K, int& n, vector<int>& prices){
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(K+1, vector<int>(2, 0)));
        for(int i=n-1; i>=0; i--){
            for(int j=K-1; j>=0; j--){
                for(int k=0; k<2; k++){
                    if(k){
                        dp[i][j][k] = max(prices[i] + dp[i+1][j+1][0], dp[i+1][j][1]);
                    }
                    else{
                        dp[i][j][k] = max(-prices[i] + dp[i+1][j][1], dp[i+1][j][0]);
                    }
                }
            }
        }
        return dp[0][0][0];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int ans = BU(k, n, prices);
        return ans;
    }
};