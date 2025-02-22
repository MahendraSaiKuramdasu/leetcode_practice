class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int ans = 0;
        int mycnt = n/3;
        sort(piles.rbegin(), piles.rend());
        for(int i=1; i<n && mycnt > 0; i+=2){
            ans += piles[i];
            mycnt--;
        }
        return ans;
    }
};