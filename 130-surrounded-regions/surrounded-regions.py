
dir = [[0,1], [0,-1], [1,0], [-1,0]]

def not_out_of_bound(i, j, n, m):
    if i < 0 or j < 0 or i >= n or j >= m:
        return False
    return True

def boundary_check(i, j, n, m):
    if i == 0 or i == n-1 or j == 0 or j == m-1:
        return True
    return False

def change_dfs(i, j, n, m, board, vis):
    board[i][j] = "X"
    vis[i][j] = 0
    for d in dir:
        x = i + d[0]
        y = j + d[1]
        if not_out_of_bound(x, y, n, m) and vis[x][y] == 1:
            change_dfs(x, y, n, m, board, vis)

def dfs(i, j, n, m, board, vis, flag):
    vis[i][j] = 1
    if boundary_check(i, j, n, m):
        flag[0] = False 
    for d in dir:
        x = i + d[0]
        y = j + d[1]
        if not_out_of_bound(x, y, n, m) and board[x][y] != "X" and vis[x][y] != 1:
            dfs(x, y, n, m, board, vis, flag)

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        n = len(board)
        m = len(board[0])
        vis = [[0 for _ in range(m)]for _ in range(0, n)]
        change = []
        for i in range(0, n):
            for j in range(0, m):
                if board[i][j] == "O" and vis[i][j] == 0:
                    flag = [True]
                    dfs(i, j, n, m, board, vis, flag)
                    if flag[0] == True:
                        change.append([i,j])
        for i in change:
            change_dfs(i[0], i[1], n, m, board, vis)


        