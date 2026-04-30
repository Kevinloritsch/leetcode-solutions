// Last updated: 4/30/2026, 8:37:06 AM
1class Solution {
2public:
3    int maxPathScore(vector<vector<int>>& grid, int k) {
4        vector<vector<vector<int>>> memo(
5            grid.size(),
6            vector<vector<int>>(
7                grid[0].size(),
8                vector<int>(k + 1, INT_MIN)
9            )
10        );
11        int result = maxPathScoreDP(grid, memo, k, 0, 0);
12        return (result < 0 ? -1 : result);
13    }
14
15    int maxPathScoreDP(vector<vector<int>>& grid, vector<vector<vector<int>>>& memo, int k, int i, int j) {
16        if(k < 0) return INT_MIN / 3;
17        if(i == grid.size() - 1 && j == grid[i].size() - 1) {
18            int newk = grid[i][j];
19            if(grid[i][j] == 2) newk--;
20            if(k - newk < 0) return INT_MIN / 3;
21            return grid[i][j];
22        }
23        if(i > grid.size() - 1 || j > grid[i].size() - 1) return INT_MIN / 3;
24        if(memo[i][j][k] != INT_MIN) return memo[i][j][k];
25
26        int newk = k - grid[i][j];
27        if(grid[i][j] == 2) newk++;
28        return memo[i][j][k] = grid[i][j] + max(maxPathScoreDP(grid, memo, newk, i + 1, j), maxPathScoreDP(grid, memo, newk, i, j+1));
29    }
30};