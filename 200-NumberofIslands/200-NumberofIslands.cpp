// Last updated: 4/2/2026, 1:07:40 PM
1class Solution {
2public:
3    int numIslands(vector<vector<char>>& grid) {
4        int islandCount = 0;
5
6        for (int i = 0; i < grid.size(); ++i) {
7            for (int j = 0; j < grid[i].size(); ++j) {
8                if(grid[i][j] == '0') continue;
9                ++islandCount;
10                destroyIsland(grid, i, j);
11            }
12        }
13
14        return islandCount;
15    }
16
17    void destroyIsland(vector<vector<char>>& grid, int i, int j) {
18        if(i < 0 || i > grid.size() - 1) return;
19        if(j < 0 || j > grid[i].size() - 1) return;
20        if(grid[i][j] == '0') return;
21        grid[i][j] = '0';
22        destroyIsland(grid, i + 1, j);
23        destroyIsland(grid, i, j + 1);
24        destroyIsland(grid, i - 1, j);
25        destroyIsland(grid, i, j - 1);
26
27    }
28
29};