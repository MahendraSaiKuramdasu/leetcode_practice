
dir = [[0,1],[0,-1],[1,0],[-1,0]]

def check(i, j, n, m, grid):
    if i>=0 and i < n and j >= 0 and j < m and grid[i][j] == "1":
        return True
    return False

def dfs(i, j, n, m, grid):
    grid[i][j] = "0"
    for d in dir:
        x = i + d[0]
        y = j + d[1]
        if check(x, y, n, m, grid):
            dfs(x, y, n, m, grid)


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])
        island_cnt = 0
        # visited matrix
        # visited = [[0 for _ in range(m)] for _ in range(n)]
        # iteration of matrix
        for i in range(0, n):
            for j in range(0, m):
                if grid[i][j] == "1":
                    dfs(i, j, n, m, grid)
                    island_cnt +=1

        return island_cnt
        