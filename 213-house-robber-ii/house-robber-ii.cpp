class Solution {
public:

    int dp[101];

    int TD(int n, int st, vector<int>& nums){
        if(n < st) return 0;
        if(dp[n] != -1) return dp[n];
        int step1 = TD(n-1, st, nums);
        int step2 = nums[n] + TD(n-2, st, nums);
        dp[n] =  max(step1, step2);
        return dp[n];
    }

    // int BU(int n, int st, vector<int>& nums){

    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        n--; 
        memset(dp, -1, sizeof(dp));
        int ans1 = TD(n, 1, nums);
        memset(dp, -1, sizeof(dp));
        int ans2 = TD(n-1, 0, nums);
        return max(ans1, ans2);
    }
};