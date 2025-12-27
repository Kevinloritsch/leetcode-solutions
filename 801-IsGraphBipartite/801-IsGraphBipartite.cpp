// Last updated: 12/27/2025, 3:44:36 PM
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // using no cycles of odd length approach
        vector<int> coloring(graph.size(), -1);

        for(int i = 0; i < graph.size(); ++i) {
            if(coloring[i] == -1) {
                if(!dfs(graph, coloring, i, true)) return false;
            }
        }

        return true;
    }

    bool dfs (vector<vector<int>>& graph, vector<int>& coloring, int nodeCheck, int color) {
        coloring[nodeCheck] = color;

        for(auto& i : graph[nodeCheck]) {
            if(coloring[i] == -1) {
                if(!dfs(graph, coloring, i, !color)) return false;
            }

            // by finding a neighbor w the same color we found an odd cycle
            else if (coloring[i] == color) return false;
        }

        return true;
    }
};