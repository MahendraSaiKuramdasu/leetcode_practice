class Solution {
public:

    int dp[20][4001];

    int TD(int n, int target, vector<int>& nums){
        if(n == 0){
            if(target == 0 && nums[0] == 0) return 2;
            return abs(target) == nums[0];
        }
        if(dp[n][target + 2000] != -1) return dp[n][target + 2000];
        int add = TD(n-1, target+nums[n], nums);
        int sub = TD(n-1, target-nums[n], nums);
        return dp[n][target + 2000] = (add + sub);
    }



    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return TD(n-1, target, nums);
    }
};