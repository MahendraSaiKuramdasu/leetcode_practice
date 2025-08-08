def dfs(i, n, adj, vis, curr_time, max_time, informTime):
    vis[i] = 1
    curr_time += informTime[i]
    max_time[0] = max(max_time[0], curr_time)
    for j in range(0, len(adj[i])):
        if vis[adj[i][j]] != 1:
            dfs(adj[i][j], n, adj, vis, curr_time, max_time, informTime)


class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        n = len(manager)
        # adj list
        adj = [[] for _ in range(0,n)]
        # fill adj list
        for i in range(0, n):
            if manager[i] != -1:
                adj[manager[i]].append(i)
        # print(adj)
        # visited arr
        vis = [0] * n
        # dfs call
        max_time = [0]
        dfs(headID, n, adj, vis, 0, max_time, informTime)
        return max_time[0]
        