// Last updated: 12/27/2025, 3:44:05 PM
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0);
        vector<int> depth(n, -1);
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                ans = max(ans, dfs(i, edges, visited, depth, 0));
            }
        }
        return ans;
    }

    int dfs(int node, vector<int>& edges, vector<int>& visited, vector<int>& depth, int d) {
        if (node == -1) return -1;
        if (visited[node] == 1) {
            return d - depth[node];
        }
        if (visited[node] == 2) return -1;

        visited[node] = 1;
        depth[node] = d;
        int res = dfs(edges[node], edges, visited, depth, d+1);
        visited[node] = 2; 
        return res;
    }

};

/*
make a visited array
if its -1 call bfs
1 + traversal number
if we come across something we've already visited... its a cycle?
yes we can assume that
we can only see one thing at a time
so if we come across it twice
its guarenteed a cycle
current depth of the traversal
0 is 1
3 is 2
2 is 3
4 is 4
3 is 5
5 - 2 = 3
return 3 + 1

*/