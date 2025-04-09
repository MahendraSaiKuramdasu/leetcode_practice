class Solution {
public:

    int dp[2502][2501];

    int TD(int p, int i, int n, vector<int>& nums){
        if(i == n) return 0;
        if(dp[p+1][i] != -1) return dp[p+1][i];
        int ans = 0;
        if(p == -1 || nums[p] < nums[i]){
            ans = 1 + TD(i, i+1, n, nums);
        }
        // else{
        //     ans = TD(i, i+1, n, nums);
        // }
        ans = max(ans, TD(p, i+1, n, nums));
        return dp[p+1][i] = ans; 
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int ans = TD(-1, 0, n, nums);
        return ans;
    }
};