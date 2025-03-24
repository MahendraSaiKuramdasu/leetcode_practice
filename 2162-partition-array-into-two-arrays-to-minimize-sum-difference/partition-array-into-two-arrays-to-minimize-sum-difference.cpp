class Solution {
public:

    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int n = N / 2;
        vector<vector<int>> left(n + 1), right(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            int sz = 0, lt = 0, rt = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sz++;
                    lt += nums[i];
                    rt += nums[i + n];
                }
            }
            left[sz].push_back(lt);
            right[sz].push_back(rt);
        }

        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

        long long mini = LLONG_MAX;
        for (int i = 0; i <= n; i++) {
            for (auto& a : left[i]) {
                auto itr = lower_bound(right[n - i].begin(), right[n - i].end(), (sum / 2) - a);
                if (itr != right[n - i].end()) {
                    mini = min(mini, abs(sum - 2 * (a + *itr)));
                }
                if (itr != right[n - i].begin()) {
                    --itr;
                    mini = min(mini, abs(sum - 2 * (a + *itr)));
                }
            }
        }

        return static_cast<int>(mini);
    }
};