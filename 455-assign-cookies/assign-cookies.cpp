class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size();
        int m = s.size();
        int j=0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            while(j<m && s[j]<g[i]){
                j++;
            }
            if(j >= m) break;
            cnt++;
            j++;
        }
        return cnt;
    }
};