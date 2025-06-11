class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        n = len(nums)
        least = [0] * n
        mini = 2**31
        maxi = -2**31
        for i in range(0, n):
            least[i] = mini
            mini = min(mini, nums[i])

        for i in range(n-1, -1, -1):
            if least[i] < nums[i] and nums[i] < maxi:
                return True
            
            maxi = max(maxi, nums[i])

        return False