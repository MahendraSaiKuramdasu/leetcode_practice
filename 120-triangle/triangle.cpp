class Solution {
public:

    int TD(int i, int j, int& n, vector<vector<int>>& TRI, vector<vector<int>>& dp){
        if(i == n-1){
            return TRI[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = TRI[i][j] + min( TD(i+1, j, n, TRI, dp) , TD(i+1, j+1, n, TRI, dp) );
        return dp[i][j];
    }

    int minimumTotal(vector<vector<int>>& TRI) {
        int n = TRI.size();
        vector<vector<int>> dp = TRI;
        for(auto& i:dp){
            fill(i.begin(), i.end(), -1);
        }
        return TD(0, 0, n, TRI, dp);
    }
};