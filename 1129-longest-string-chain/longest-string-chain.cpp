    bool customSort(string& a, string& b){
        return (a.length() < b.length());
    }

class Solution {
public:

    int dp[1002][1001];

    int TD(int p, int i, int n, vector<string>& words){
        if(i == n) return 0;
        if(dp[p+1][i] != -1){
            return dp[p+1][i];
        }
        int ans = 0;
        if(p == -1){
            ans = 1 + TD(i, i+1, n, words);
        }
        else if(words[p].length() < words[i].length()){
            for(int j=0; j<words[i].length(); j++){
                string str1 = words[i].substr(0, j);
                str1 = str1 + words[i].substr(j+1);
                if(words[p] == str1){
                    ans = 1 + TD(i, i+1, n, words);
                    break;
                }
            }
        }
        ans = max(ans, TD(p, i+1, n, words));
        return dp[p+1][i] = ans;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), customSort);
        memset(dp, -1, sizeof(dp));
        int ans = TD(-1, 0, n, words);
        return ans;
    }
};