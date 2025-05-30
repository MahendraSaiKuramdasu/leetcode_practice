class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        pre = int(-1e9-1)
        n = len(nums)
        nums.sort()
        for i in nums:
            if i != pre:
                cnt = 0
            cnt += 1
            if cnt > n/2:
                return i
            pre = i
        return -1