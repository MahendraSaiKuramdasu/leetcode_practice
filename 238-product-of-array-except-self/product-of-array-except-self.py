class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        product = 1
        zero_index = -1
        result_list = [0] * len(nums)

        for j,i in enumerate(nums):
            if i == 0:
                if zero_index != -1:
                    return result_list
                zero_index = j
            else:
                product *= i
        
        if zero_index != -1:
            result_list[zero_index] = int(product)
            return result_list
        
        for j,i in enumerate(nums):
            result_list[j] = int(product/i)
        
        return result_list