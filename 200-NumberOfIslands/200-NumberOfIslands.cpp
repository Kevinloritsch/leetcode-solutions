// Last updated: 12/27/2025, 3:44:55 PM
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCounter = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == '1') {
                    ++islandCounter;
                    destroyIsland(grid, i, j);
                }
            }
        }
        return islandCounter;
    }

    void destroyIsland(vector<vector<char>>& grid, int i, int j) {

        if(i < 0 || i > grid.size() - 1 || j < 0 || j > grid[i].size() - 1 || grid[i][j] == '0') return;

        grid[i][j] = '0';
        destroyIsland(grid, i-1, j);
        destroyIsland(grid, i+1, j);
        destroyIsland(grid, i, j-1);
        destroyIsland(grid, i, j+1);

    }
};