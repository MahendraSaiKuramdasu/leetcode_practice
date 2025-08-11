from queue import Queue


dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]

def chech_bount(i, j, n, m):
    if i < 0 or j < 0 or i >= n or j >= m:
        return False
    return True

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        vis = [[0 for _ in range(0, m)]for _ in range(0, n)]
        cnt = -1
        fresh_oranges = 0

        # queue initialization
        queue = Queue()
        # getting all rotten oranges into queue

        for i in range(0, n):
            for j in range(0, m):
                if grid[i][j] == 2:
                    # getting into queue
                    queue.put([i,j])
                elif grid[i][j] == 1:
                    fresh_oranges += 1 

        # print(fresh_oranges)

        if queue.qsize() == 0 and fresh_oranges == 0:
            return 0
        
        while queue.qsize() > 0:
            q_n = queue.qsize()

            while q_n > 0:
                node = queue.get()
                # pop from queue
                i = node[0]
                j = node[1]

                for d in dir:
                    x = i + d[0]
                    y = j + d[1]
                    if chech_bount(x, y, n, m) and vis[x][y] == 0 and grid[x][y] == 1:
                        # adding x, y into the queue 
                        queue.put([x,y])
                        vis[x][y] = 1
                        fresh_oranges -= 1
                q_n -= 1
            
            cnt += 1

        # print(fresh_oranges)

        if fresh_oranges >= 1:
            return -1

        return cnt