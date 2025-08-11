from queue import Queue

dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]

def bound(i, j, n, m):
    if i < 0 or j < 0 or i >= n or j >= m:
        return False
    return True

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        n = len(mat)
        m = len(mat[0])
        vis = [[0 for _ in range(0, m)]for _ in range(0, n)]
        q = Queue()
        for i in range(0, n):
            for j in range(0, m):
                if mat[i][j] == 0:
                    q.put([i,j])

        cnt = 0

        while q.qsize() > 0:
            q_n = q.qsize()
            cnt+=1
            while q_n > 0:
                q_n-=1
                node = q.get()
                i = node[0]
                j = node[1]
                for d in dir:
                    x = i + d[0]
                    y = j + d[1]
                    if bound(x, y, n, m) and vis[x][y] == 0 and mat[x][y] == 1:
                        vis[x][y] = 1
                        mat[x][y] = cnt
                        q.put([x,y])

        return mat