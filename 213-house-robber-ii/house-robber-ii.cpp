class Solution {
public:

    // int dp[101];

    // int TD(int n, int st, vector<int>& nums){
    //     if(n < st) return 0;
    //     if(dp[n] != -1) return dp[n];
    //     int step1 = TD(n-1, st, nums);
    //     int step2 = nums[n] + TD(n-2, st, nums);
    //     dp[n] =  max(step1, step2);
    //     return dp[n];
    // }

    int BU(int n, int st, vector<int>& nums){
        vector<int> dp(n+1, INT_MIN);
        dp[st] = nums[st];
        for(int i=st+1; i<=n; i++){
            int ans1 = dp[i-1];
            int addition = 0;
            if(i-2 >= st){
                addition = dp[i-2];
            }
            int ans2 = nums[i] + addition;
            dp[i] = max(ans1, ans2);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        n--; 
        // memset(dp, -1, sizeof(dp));
        // int ans1 = TD(n, 1, nums);
        // memset(dp, -1, sizeof(dp));
        // int ans2 = TD(n-1, 0, nums);
        int ans1 = BU(n, 1, nums);
        int ans2 = BU(n-1, 0, nums);
        return max(ans1, ans2);
    }
};