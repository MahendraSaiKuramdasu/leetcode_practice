class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int buy = INT_MAX;
        for(int i=0; i<n; i++){
            if(prices[i] < buy){
                buy = prices[i];
            }
            else{   
                int currProfit = prices[i] - buy;
                profit = max(currProfit, profit);
            }
        }
        return profit;
    }
};