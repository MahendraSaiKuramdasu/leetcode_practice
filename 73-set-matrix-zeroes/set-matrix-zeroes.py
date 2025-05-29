class Solution:
    def setZeroes(self, mat: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(mat)
        m = len(mat[0])
        row = [0] * n
        col = [0] * m
        for i in range(0, n):
            for j in range(0, m):
                if mat[i][j] == 0:
                    row[i] = 1
                    col[j] = 1
        
        for i in range(0, n):
            for j in range(0, m):
                if row[i] == 1 or col[j] == 1:
                    mat[i][j] = 0
        