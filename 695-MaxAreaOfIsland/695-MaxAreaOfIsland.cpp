// Last updated: 12/27/2025, 3:44:43 PM
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                max_area = std::max(max_area, maxAreaDFS(grid, i, j));
            }
        }

        return max_area;
    }

    int maxAreaDFS(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0) return 0;

        grid[i][j] = 0;

        return 1 + maxAreaDFS(grid, i - 1, j) + maxAreaDFS(grid, i + 1, j) + maxAreaDFS(grid, i, j - 1) + maxAreaDFS(grid, i, j + 1);
    }
};