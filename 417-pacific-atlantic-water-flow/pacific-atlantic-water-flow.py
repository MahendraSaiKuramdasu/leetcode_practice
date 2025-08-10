dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]

def not_out_of_bound(i, j, n, m):
    if i<0 or j<0 or i>= n or j>= m:
        return False
    return True

def dfs(i, j, n, m, grid, vis):
    vis[i][j] = 1
    for d in dir:
        x = i + d[0]
        y = j + d[1]
        if not_out_of_bound(x, y, n, m) and grid[x][y] >= grid[i][j] and vis[x][y] != 1:
            dfs(x, y, n, m, grid, vis)

class Solution:
    def pacificAtlantic(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        m = len(grid[0])
        vis_p = [[0 for _ in range(0, m)] for _ in range(0, n)]
        vis_a = [[0 for _ in range(0, m)] for _ in range(0, n)]
        res = []
        for i in range(0, n):
            for j in range(0, m):
                if i == 0 or j == 0:
                    dfs(i, j, n, m, grid, vis_p)
                if i == n-1 or j == m-1:
                    dfs(i, j, n, m, grid, vis_a)

        for i in range(0, n):
            for j in range(0, m):
                if vis_p[i][j] == 1 and vis_a[i][j] == 1:
                    res.append([i,j])

        return res