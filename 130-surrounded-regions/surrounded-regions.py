
dir = [[0,1], [0,-1], [1,0], [-1,0]]

def not_out_of_bound(i, j, n, m):
    if i < 0 or j < 0 or i >= n or j >= m:
        return False
    return True

def boundary_check(i, j, n, m):
    if i == 0 or i == n-1 or j == 0 or j == m-1:
        return True
    return False

def dfs(i, j, n, m, board, vis):
    vis[i][j] = "O"
    for d in dir:
        x = i + d[0]
        y = j + d[1]
        if not_out_of_bound(x, y, n, m) and board[x][y] == "O" and vis[x][y] == "X":
            dfs(x, y, n, m, board, vis)

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        n = len(board)
        m = len(board[0])
        vis = [["X" for _ in range(0, m)] for _ in range(0, n)]
        for i in range(0, n):
            for j in range(0, m):
                if boundary_check(i, j, n, m) and board[i][j] == "O" and vis[i][j]            ==  "X":
                    dfs(i, j, n, m, board, vis)

        for i in range(0, n):
            for j in range(0, m):
                board[i][j] = vis[i][j]



        