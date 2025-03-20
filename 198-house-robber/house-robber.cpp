class Solution {
public:

    int dp[101];

    int TD(int n, vector<int>& arr){
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int maxi = INT_MIN;
        maxi = arr[n] + TD(n-2, arr);
        maxi = max(maxi, TD(n-1, arr));
        dp[n] = maxi;
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        memset(dp, -1, sizeof(dp));
        return TD(n, nums); 
    }
};