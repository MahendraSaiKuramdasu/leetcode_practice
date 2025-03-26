class Solution {
public:

    int dp[20][4001];

    // int TD(int n, int target, vector<int>& nums){
    //     if(n == 0){
    //         if(target == 0 && nums[0] == 0) return 2;
    //         return abs(target) == nums[0];
    //     }
    //     if(dp[n][target + 2000] != -1) return dp[n][target + 2000];
    //     int add = TD(n-1, target+nums[n], nums);
    //     int sub = TD(n-1, target-nums[n], nums);
    //     return dp[n][target + 2000] = (add + sub);
    // }

    int BU(int n, int target, vector<int>& nums){
        dp[0][2000 - nums[0]] += 1; 
        dp[0][2000 + nums[0]] += 1;
        for(int i=1; i<n; i++){
            for(int j=-1000; j<=1000; j++){
                int add = dp[i-1][2000 + (j + nums[i])];
                int sub = dp[i-1][2000 + (j - nums[i])];
                dp[i][2000 + j] = (add + sub);
            }
        }
        return dp[n-1][2000 + target]; 
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp, 0, sizeof(dp));
        // return TD(n-1, target, nums);
        return BU(n, target, nums);
    }
};