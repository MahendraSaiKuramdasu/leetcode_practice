class Solution {
public:

    // int dp[101];

    // int TD(int n, vector<int>& arr){
    //     if(n < 0) return 0;
    //     if(dp[n] != -1) return dp[n];
    //     int maxi = INT_MIN;
    //     maxi = arr[n] + TD(n-2, arr);
    //     maxi = max(maxi, TD(n-1, arr));
    //     dp[n] = maxi;
    //     return dp[n];
    // }

    int BT(int n, vector<int>& arr){
        vector<int> dp(n+1, INT_MIN);
        dp[0] = arr[0];
        for(int i=1; i<=n; i++){
            int step1 = dp[i-1];
            int addition = 0;
            if(i-2 >= 0){
                addition = dp[i-2];
            }
            int step2 = arr[i] + addition;
            dp[i] = max(step1, step2);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        // memset(dp, -1, sizeof(dp));
        // return TD(n, nums); 
        return BT(n, nums);
    }
};