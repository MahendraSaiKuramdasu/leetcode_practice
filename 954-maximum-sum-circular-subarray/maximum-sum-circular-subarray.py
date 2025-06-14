class Solution:
    def maxSubarraySumCircular(self, arr: List[int]) -> int:

        n = len(arr)
        mini = 2**31
        k = 0
        maxi = -2**31
        mk = 0
        s = 0
        for i in range(0, n):
            s += arr[i]
            k += arr[i]
            mk += arr[i]
            maxi = max(maxi, mk)
            mini = min(mini, k)
            if k > 0:
                k = 0
            if mk < 0:
                mk = 0

        if s == mini:
            return maxi

        ans = s - mini

        return max(ans, maxi)

        