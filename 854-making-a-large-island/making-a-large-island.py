
dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]

def not_out_of_bound(i, j, n, m):
    if i<0 or j<0 or i>= n or j>= m:
        return False
    return True

def dfs(i, j, n, m, grid, vis):
    vis[i][j] = 1
    ans = 1
    for d in dir:
        x = i + d[0]
        y = j + d[1]
        if not_out_of_bound(x, y, n, m) and vis[x][y] != 1 and grid[x][y] == 1:
            ans += dfs(x, y, n, m, grid, vis)

    return ans

def fill_dfs(i, j, n, m, grid, vis, val, degree, cnt):
    vis[i][j] = 1
    grid[i][j] = val
    degree[i][j] = cnt
    for d in dir:
        x = i + d[0]
        y = j + d[1]
        if not_out_of_bound(x, y, n, m) and vis[x][y] != 1 and grid[x][y] == 1:
            fill_dfs(x, y, n, m, grid, vis, val, degree, cnt)

class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        maxi = 0
        vis = [[0 for _ in range(0 , m)]for _ in range(0, n)]
        for i in range(0, n):
            for j in range(0, m):
                if grid[i][j] == 1 and vis[i][j] == 0:
                    val = dfs(i, j, n, m, grid, vis)
                    grid[i][j] = val
                    maxi = max(maxi, val)

        vis = [[0 for _ in range(0 , m)]for _ in range(0, n)]
        degree = [[0 for _ in range(0 , m)]for _ in range(0, n)]
        cnt = 1

        for i in range(0, n):
            for j in range(0, m):
                if grid[i][j] > 0 and vis[i][j] == 0:
                    if grid[i][j] > 1:
                        fill_dfs(i, j, n, m, grid, vis, grid[i][j], degree, cnt)
                    else:
                        degree[i][j] = cnt
                    cnt+=1

        # print(grid)
        # print(degree)


        for i in range(0, n):
            for j in range(0, m):
                if grid[i][j] == 0:
                    val = 1
                    st = set()
                    for d in dir:
                        x = i + d[0]
                        y = j + d[1]
                        if not_out_of_bound(x, y, n, m):
                            if degree[x][y] not in st:
                                val += grid[x][y]
                                st.add(degree[x][y])
                    maxi = max(maxi, val)

        return maxi