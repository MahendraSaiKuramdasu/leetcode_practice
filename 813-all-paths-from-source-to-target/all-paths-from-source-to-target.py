def dfs(i, n, graph, vis, carry, res):
    vis[i] = 1
    carry = carry.copy()
    carry.append(i)
    if i == n:
        res.append(carry)
    for j in graph[i]:
        if vis[j] != 1:
            dfs(j, n, graph, vis, carry, res)
    vis[i] = 0


class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        vis = [0] * n
        res = []
        carry = []
        dfs(0, n-1, graph, vis, carry, res)
        return res

        