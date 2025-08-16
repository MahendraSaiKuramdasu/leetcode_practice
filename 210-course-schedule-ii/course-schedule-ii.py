from queue import Queue

class Solution:
    def findOrder(self, V: int, edges: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(0, V)]
        deg = [0] * V
        for i in edges:
            u = i[0]
            v = i[1]
            adj[u].append(v)
            deg[v]+=1
        q = Queue()
        for i in range(0, len(adj)):
            if deg[i] == 0:
                q.put(i)
        res = []
        while q.qsize() > 0:
            node = q.get()
            res.append(node)
            for i in adj[node]:
                deg[i]-=1
                if deg[i] == 0:
                    q.put(i)
                    
        if len(res) != V:
            return []

        res.reverse()

        return res        