class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int ans = 0;
        int i = -1;
        int j = n;
        sort(piles.rbegin(), piles.rend());
        while(j-i>=2){
            i+=2;
            j-=1;
            ans += piles[i];
        }
        return ans;
    }
};