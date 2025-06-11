class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        
        n = len(nums)
        for i in range(0, n):
            if nums[i] < 0:
                nums[i] = -1
            else:
                while nums[i] > 0 and nums[i] != i+1:
                    if nums[i] > n:
                        nums[i] = -1
                        break
                    elif nums[i] == nums[nums[i]-1] :
                        break
                    else:
                        temp = nums[i]-1
                        nums[i], nums[temp] = nums[temp], nums[i]

        for i in range(0, n):
            if i+1 != nums[i]:
                return i+1

        return n+1
