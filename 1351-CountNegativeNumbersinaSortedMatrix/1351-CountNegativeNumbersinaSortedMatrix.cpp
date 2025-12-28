// Last updated: 12/27/2025, 4:21:04 PM
1class Solution {
2public:
3    int countNegatives(vector<vector<int>>& grid) {
4
5        int topRow = 0;
6        int topCol = 0;
7
8        int count = 0;
9
10        for(int i = grid.size() - 1; i >= topRow; --i) {
11            for(int j = grid[0].size() - 1; j >= topCol; --j) {
12                if(grid[i][j] >= 0) {
13                    topCol = j;
14                }
15                else ++count;
16            }
17        }
18
19        return count;
20        
21    }
22};