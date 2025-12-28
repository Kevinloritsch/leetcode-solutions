// Last updated: 12/27/2025, 3:44:30 PM
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> colors(n+1, 0);

        vector<vector<int>> adjList(n+1);
        for(auto & i : paths) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }

        for(int i = 1; i < n+1; ++i) {
            gardenColor(i, adjList, colors);
        }
        colors.erase(colors.begin());
        return colors;
    }

    void gardenColor(int node, vector<vector<int>>& adjList, vector<int>& colors) {
        if (colors[node] != 0) return;

        vector<bool> used(5, false);

        for (int i : adjList[node]) if (colors[i] != 0) used[colors[i]] = true;

        for (int c = 1; c <= 4; c++) {
            if (!used[c]) {
                colors[node] = c;
                break;
            }
        }

        for (int i : adjList[node]) if (colors[i] == 0) gardenColor(i, adjList, colors);
    }
};

