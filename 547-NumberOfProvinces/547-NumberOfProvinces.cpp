// Last updated: 12/27/2025, 3:44:48 PM
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(), -1);

        int num = 0;

        for(int i = 0; i < isConnected.size(); ++i) {
            if(visited[i] == -1) {
                num++;
                dfs(isConnected, visited, i);
            }
        }

        return num;
    }

    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int i) {
        if(visited[i] == 2) return;
        visited[i] = 2;
        for(int j = 0; j < isConnected.size(); ++j) {
            if(isConnected[i][j] == 1 && visited[j] != 2) {
                dfs(isConnected, visited, j);
            }
        }
    }
};