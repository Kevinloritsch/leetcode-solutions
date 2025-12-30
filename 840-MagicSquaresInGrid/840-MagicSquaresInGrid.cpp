// Last updated: 12/30/2025, 1:00:29 PM
1class Solution {
2public:
3    int numMagicSquaresInside(vector<vector<int>>& grid) {
4
5        if(grid.size() < 3) return 0;
6        if(grid[0].size() < 3) return 0;
7
8        int total = 0;
9
10        for(int i = 0; i < grid.size() - 2; ++i) {
11            for(int j = 0; j < grid[i].size() - 2; ++j) {
12                if(validSquare(grid, i, j)) ++total;
13            }
14        }
15
16        return total;
17        
18    }
19
20    bool validSquare(vector<vector<int>>& grid, int i, int j) {
21        int sum = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
22
23        if(sum != grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2]) return false;
24
25        for(int k = 0; k < 3; ++k) {
26            if(sum != grid[i+k][j] + grid[i+k][j+1] + grid[i+k][j+2]) return false;
27            if(sum != grid[i][j+k] + grid[i+1][j+k] + grid[i+2][j+k]) return false;
28        }
29
30        vector<int> checker(10, -1);
31        int val;
32
33        for(int m = 0; m < 3; ++m) {
34            for(int n = 0; n < 3; ++n) {
35                val = grid[i+m][j+n];
36                // only 1-9
37                if(val > 9 || !val) return false;
38                // all unique
39                if(checker[val] == -1) checker[val] = 0;
40                else return false;
41            }
42        }
43
44        return true;
45    }
46};