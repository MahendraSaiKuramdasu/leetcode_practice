    bool customSort(string& a, string& b){
        return (a.length() < b.length());
    }

class Solution {
public:

    // int dp[1002][1001];

    // int TD(int p, int i, int n, vector<string>& words){
    //     if(i == n) return 0;
    //     if(dp[p+1][i] != -1){
    //         return dp[p+1][i];
    //     }
    //     int ans = 0;
    //     if(p == -1){
    //         ans = 1 + TD(i, i+1, n, words);
    //     }
    //     else if(words[p].length() < words[i].length()){
    //         for(int j=0; j<words[i].length(); j++){
    //             string str1 = words[i].substr(0, j);
    //             str1 = str1 + words[i].substr(j+1);
    //             if(words[p] == str1){
    //                 ans = 1 + TD(i, i+1, n, words);
    //                 break;
    //             }
    //         }
    //     }
    //     ans = max(ans, TD(p, i+1, n, words));
    //     return dp[p+1][i] = ans;
    // }

    int BU(int n, vector<string>& words){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=i; j>=-1; j--){
                if(j == -1){
                    dp[j+1][i] = 1 + dp[i+1][i+1];
                }
                else if(words[j].length() < words[i].length()){
                    for(int t=0; t<words[i].length(); t++){
                        string s1 = words[i].substr(0, t);
                        s1 = s1 + words[i].substr(t+1);
                        if(s1 == words[j]){
                            dp[j+1][i] = 1 + dp[i+1][i+1];
                            break;
                        }
                    }
                }
                dp[j+1][i] = max(dp[j+1][i], dp[j+1][i+1]);
            }
        }
        return dp[0][0];
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), customSort);
        // memset(dp, -1, sizeof(dp));
        // int ans = TD(-1, 0, n, words);
        int ans = BU(n, words);
        return ans;
    }
};