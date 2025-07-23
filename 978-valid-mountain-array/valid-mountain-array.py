class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        n = len(arr)
        left_size = 0
        right_size = 0
        for i in range(0, n-1):
            if arr[i] < arr[i+1]:
                left_size+=1
            else:
                break
        for i in range(n-1, 0, -1):
            if arr[i] < arr[i-1]:
                right_size+=1
            else:
                break

        total_size = left_size + right_size
        if left_size == 0 or right_size == 0:
            return False

        if total_size == n -1:
            return True

        return False

        