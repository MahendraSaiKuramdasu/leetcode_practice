class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k %= n
        s1, e1, s2, e2 = 0, n-k-1, n-k, n-1

        while s1 < e1:
            # swap
            nums[s1], nums[e1] = nums[e1], nums[s1]
            s1 += 1
            e1 -= 1
        
        while s2 < e2:
            # swap
            nums[s2], nums[e2] = nums[e2], nums[s2]
            s2 += 1
            e2 -= 1

        s = 0
        e = n-1

        while s < e:
            nums[s], nums[e] = nums[e], nums[s]
            s += 1
            e -= 1 

        