class Solution {
public:

    // int dp[201][20001];

    // int TD(int n, int sum, vector<int>& nums){
    //     if(n < 0) return 0;
    //     if(sum < 0) return 0;
    //     if(sum == nums[n]) return 1;
    //     if(dp[n][sum] != -1) return dp[n][sum];
    //     int exclude = TD(n-1, sum, nums);
    //     int include = TD(n-1, sum-nums[n], nums);
    //     dp[n][sum] = (exclude || include);
    //     return dp[n][sum];
    // }

    bool BU(int n, int sum, vector<int>& nums){
        // vector<vector<int>> dp(n, vector<int>(sum*2+1, 0));
        vector<int> pre(sum*2+1, 0);
        vector<int> curr(sum*2+1, 0);
        pre[0] = 1;
        pre[nums[0]] = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<=sum; j++){
                // int exclude = dp[i-1][j];
                int exclude = pre[j];
                int include = 0;
                if(j - nums[i] >= 0){
                    // include = dp[i-1][j - nums[i]];
                    include = pre[j - nums[i]];
                }
                // dp[i][j] = include || exclude;
                curr[j] = include || exclude;
            }
            pre = curr;
        }
        // return dp[n-1][sum];
        return curr[sum];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i:nums){
            sum += i;
        }
        if(sum%2 == 1) return false;
        sum = sum/2;
        // memset(dp, -1, sizeof(dp));
        // return TD(n-1, sum, nums);
        return BU(n, sum, nums);
    }
};