class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        b = 0
        for i in range(0, n):
            if nums[i] == 0:

                if b < i:
                    b = i+1

                while b < n and nums[b] == 0:
                    b+=1
                
                if b < n:
                    nums[i], nums[b] = nums[b], nums[i]
                else: break



            
        