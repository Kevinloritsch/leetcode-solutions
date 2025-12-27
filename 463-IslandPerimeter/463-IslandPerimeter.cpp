// Last updated: 12/27/2025, 3:44:49 PM
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // iterate through i
        // iterate through j
        // if find island return dfs at that point
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 1) return dfs(grid, i, j);
            }
        }

        // return 0 if never find island

        return 0;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        // bound check
        // if visited, has a 2, return 0

        if(i < 0 || i > grid.size() - 1 || j < 0 || j > grid[i].size() - 1 || grid[i][j] == 0) return 1;
        if(grid[i][j] == 2) return 0;
        // if its an island, 
        // change it to 2
        //has a 1, return (dfs again in all 4 cardinal directions added together)
        grid[i][j] = 2;

        return (dfs(grid, i+1, j)
                + dfs(grid, i-1, j)
                + dfs(grid, i, j+1)
                + dfs(grid, i, j-1))
                ;
        
    } 
};