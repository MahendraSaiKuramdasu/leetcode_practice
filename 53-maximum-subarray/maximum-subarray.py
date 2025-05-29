class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxi_num = int(-1e4)
        num = 0
        for i in nums:
            num+=i
            maxi_num = max(maxi_num, num)
            if num<0: num = 0
        
        return maxi_num
        