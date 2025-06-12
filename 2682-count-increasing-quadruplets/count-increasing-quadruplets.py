
class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:

        n = len(nums)
        ans = 0
        left = [[0 for _ in range(n)] for _ in range(n)]
        right = [[0 for _ in range(n)] for _ in range(n)]
        cnt = 0

        for k in range(n-1, -1, -1):
            cnt = 0
            for j in range(0, k):
                left[j][k] = cnt
                if nums[j] < nums[k]:
                    cnt += 1
        
        cnt = 0

        for j in range(0, n):
            cnt = 0
            for k in range(n-1, j, -1):
                right[j][k] = cnt
                if nums[j] < nums[k]:
                    cnt += 1

        for j in range(0, n):
            for k in range(n-1, j, -1):
                if nums[k] < nums[j]:
                    ans += (left[j][k] * right[j][k])

        return ans

        

        
        