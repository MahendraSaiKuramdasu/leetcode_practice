class Solution {
public:

    // int TD(int i, bool status, int cnt, int& n, vector<int>& prices){
    //     if(cnt == 2 || i == n) return 0;
    //     int ans= 0;
    //     if(status){
    //         ans = max(prices[i] + TD(i+1, 0, cnt+1, n, prices), TD(i+1, 1, cnt, n, prices)); 
    //     }
    //     else{
    //         ans = max(-prices[i] + TD(i+1, 1, cnt, n, prices), TD(i+1, 0, cnt, n, prices));
    //     }
    //     return ans;
    // }

    int BU(int& n, vector<int>& prices){
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2, 0)));
        for(int i=n-1; i>=0; i--){
            for(int j=1; j>=0; j--){
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

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = BU(n, prices);
        // int ans = TD(0, 0, 0, n, prices);
        return ans;
    }
};