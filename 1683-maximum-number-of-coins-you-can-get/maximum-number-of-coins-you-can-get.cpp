class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        n-=(n/3);
        int ans = 0;
        sort(piles.rbegin(), piles.rend());
        for(int i=1; i<n; i+=2){
            ans += piles[i];
        }
        return ans;
    }
};