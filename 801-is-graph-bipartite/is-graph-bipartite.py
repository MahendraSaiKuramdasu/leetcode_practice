def dfs(i, curr_color, graph, color):
    color[i] = curr_color
    check_color = (curr_color + 1) % 2
    for j in graph[i]:
        if color[j] == -1:
            flag = dfs(j, check_color, graph, color)
            if flag == False:
                return False
        else:
            if color[j] != check_color:
                return False

    return True


class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1] * n
        for i in range(0, n):
            if color[i] == -1:
                flag = dfs(i, 1, graph, color)

                if (flag == False):
                    return False

        return True