// Last updated: 12/27/2025, 3:44:06 PM
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {

        // dfs on the graph
        // make a vector of number of disjoint sets w visited and number of elements per set
        // for each set, multiply the number in that set by number of other nodes yay

        vector<vector<int>> adj(n);
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> visited(n, 0);
        vector<int> setSize;
        for(int i = 0; i < adj.size(); ++i) {
            if(visited[i] == 1) continue;
            setSize.push_back(dfs(adj, visited, i));

        }

        long long total = 0;
        long long remaining = n;
        for (int i : setSize) {
            remaining -= i;
            total += i * remaining;
        }
        return total;

        
    }

    int dfs(vector<vector<int>>& adj, vector<int>& visited, int i) {
        if (visited[i]) return 0;
        visited[i] = 1;

        int sum = 1;

        for(auto j : adj[i]) {
            sum += dfs(adj, visited, j);
        }

        return sum;
    }
};