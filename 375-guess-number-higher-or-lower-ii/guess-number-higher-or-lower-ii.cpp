class Solution {
public:

    int dp[200+1][200+1];

    int solve(int start, int end){
        if(start >= end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int curr = INT_MAX;
        for(int i=start; i<= end; i++){
            int temp = i + max(solve(start, i-1), solve(i+1, end));
            curr = min(curr, temp);
        }
        dp[start][end] = curr;
        return curr;
    }

    int getMoneyAmount(int n) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(1, n);
        return ans;
    }
};