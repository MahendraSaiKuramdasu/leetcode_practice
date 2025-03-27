class Solution {
public:

    // int TD(int i, int j, int& n, int& m, string& s1, string& s2){
    //     if(i == n || j == m){
    //         return 0;
    //     }
    //     int same = 0, notSame = 0;
    //     if(s1[i] == s2[j]){
    //         same = 1 + TD(i+1, j+1, n, m, s1, s2);
    //     }
    //     else{
    //         notSame = max(TD(i+1, j, n, m, s1, s2) , TD(i, j+1, n, m, s1, s2));
    //     }
    //     return max(same, notSame);
    // }

    int BU(int& n, int& m, string& s1, string& s2){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int same = 0, notSame = 0;
                if(s1[i] == s2[j]){
                    same = 1 + dp[i+1][j+1];
                }
                else{
                    notSame = max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = max(same, notSame);
            }
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        // return TD(0, 0, n, m, text1, text2);
        return BU(n, m, text1, text2);
    }
};