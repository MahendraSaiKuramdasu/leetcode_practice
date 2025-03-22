class Solution {
public:

    int dp[201][20001];

    int TD(int n, int sum, vector<int>& nums){
        if(n < 0) return 0;
        if(sum < 0) return 0;
        if(sum == nums[n]) return 1;
        if(dp[n][sum] != -1) return dp[n][sum];
        int exclude = TD(n-1, sum, nums);
        int include = TD(n-1, sum-nums[n], nums);
        dp[n][sum] = (exclude || include);
        return dp[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i:nums){
            sum += i;
        }
        if(sum%2 == 1) return false;
        sum = sum/2;
        memset(dp, -1, sizeof(dp));
        return TD(n-1, sum, nums);
    }
};