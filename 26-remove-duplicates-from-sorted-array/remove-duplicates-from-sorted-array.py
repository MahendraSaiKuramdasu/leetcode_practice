class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        pre = -101
        unique_index = 0
        cnt = 0
        for i in range(0, len(nums)):
            if pre != nums[i]:
                pre = nums[i]
                nums[i], nums[unique_index] = nums[unique_index], nums[i]
                cnt += 1
                unique_index += 1

        return cnt