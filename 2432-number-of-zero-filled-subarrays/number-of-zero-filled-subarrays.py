class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        total = 0
        cnt = 0
        for i in nums:
            if i == 0:
                cnt += 1
                total += cnt
            else:
                cnt = 0
        
        return total