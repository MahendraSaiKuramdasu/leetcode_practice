class Solution {
public:

    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // sort(nums.begin(), nums.end());
        int n = N/2;
        vector<vector<int>> left(n+1), right(n+1);
        for(int maxi=0; maxi<(1<<n); maxi++){
            int sz = 0;
            int lt = 0;
            int rt = 0;
            for(int i=0; i<n; i++){
                if(maxi & (1<<i)){
                    sz++;
                    lt+=nums[i];
                    rt+=nums[i+n];
                }
            }
            left[sz].push_back(lt);
            right[sz].push_back(rt);
        }
        for(int i=1; i<n; i++){
            sort(right[i].begin(), right[i].end());
        }
        int mini = min(abs(sum - 2*left[n][0]), abs(sum - 2*right[n][0]));
        // int mini = INT_MAX;
        for(int i=1; i<n; i++){
            for(auto& a : left[i]){
                int b = sum/2 - a;
                auto itr = lower_bound(right[n-i].begin(), right[n-i].end(), b);
                if(itr != right[n-i].end()){
                    mini = min(mini, abs(sum - 2*(a+(*itr))));
                }
                if(itr != right[n-i].begin()){
                    --itr;
                    mini = min(mini, abs(sum - 2*(a+(*itr))));
                }
            }
        }
        return mini;
    }
};