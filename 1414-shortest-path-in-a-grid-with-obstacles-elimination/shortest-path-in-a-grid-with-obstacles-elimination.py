from queue import Queue

dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]

def bound(i, j, n, m):
    if i < 0 or j < 0 or i >= n or j >= m:
        return False
    return True

class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        n = len(grid)
        m = len(grid[0])
        vis = [[k+1 for _ in range(0, m)]for _ in range(0, n)]
        q = Queue()
        q.put([0,0,0])
        cnt = 0
        while q.qsize() > 0:
            q_len = q.qsize()
            while q_len > 0:
                q_len -= 1
                cell = q.get()
                i = cell[0]
                j = cell[1]
                cost = cell[2]
                if i == n-1 and j == m-1:
                    return cnt
                for d in dir:
                    x = i + d[0]
                    y = j + d[1]
                    if bound(x, y, n, m):
                        curr_cost = cost
                        if grid[x][y] == 1:
                            curr_cost += 1
                        if curr_cost <= k and vis[x][y] > curr_cost:
                            vis[x][y] = curr_cost
                            q.put([x,y,curr_cost])

            cnt += 1

        return -1


