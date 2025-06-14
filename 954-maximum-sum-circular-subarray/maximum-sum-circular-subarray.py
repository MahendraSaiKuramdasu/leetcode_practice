class Solution:
    def maxSubarraySumCircular(self, arr: List[int]) -> int:

        n = len(arr)
        prefix = [0] * (n+1)
        maxi = -2**31
        k = 0
        max_prefix = -2**31
        s = 0
        for i in range(0, n):
            s += arr[i]
            k += arr[i]
            maxi = max(maxi, k)
            max_prefix = max(max_prefix, s)
            if k < 0:
                k = 0
            prefix[i+1] = max_prefix
        
        s = 0
          
        for i in range(n-1, -1, -1):
            s += arr[i]
            maxi = max(maxi, (s+prefix[i]))
            
        return maxi

        