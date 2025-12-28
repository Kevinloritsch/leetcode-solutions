// Last updated: 12/27/2025, 3:44:13 PM
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);
        vector<int> visited(n, -1);

        for(auto i : edges) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }

        return dfs(adjList, visited, source, destination);
    }

    bool dfs(vector<vector<int>>& adjList, vector<int>& visited, int source, int destination) {
        if(source == destination) return true;

        if(visited[source] != -1) return false;

        visited[source] = 0;

        for(auto i : adjList[source]) {
            if(dfs(adjList, visited, i, destination)) return true;
        }
        return false;

    }
};