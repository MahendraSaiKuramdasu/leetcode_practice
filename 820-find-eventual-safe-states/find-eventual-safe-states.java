import java.util.*;

public class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;

        // Reverse graph
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        // In-degree array
        int[] deg = new int[n];

        // Build reverse graph and compute in-degrees
        for (int i = 0; i < n; i++) {
            for (int u : graph[i]) {
                adj.get(u).add(i); // reverse edge
                deg[i]++;
            }
        }

        // Kahn's algorithm
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                q.add(i);
            }
        }

        List<Integer> res = new ArrayList<>();
        while (!q.isEmpty()) {
            int node = q.poll();
            res.add(node);
            for (int neighbor : adj.get(node)) {
                deg[neighbor]--;
                if (deg[neighbor] == 0) {
                    q.add(neighbor);
                }
            }
        }

        Collections.sort(res);
        return res;
    }
}