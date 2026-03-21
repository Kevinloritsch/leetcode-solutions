// Last updated: 3/21/2026, 12:28:50 PM
1class Solution {
2public:
3    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
4        int count = 0;
5        int end = 0;
6
7        for(int j = y; j < y + k; ++j) {
8            end = x + k - 1;
9            for(int i = x; i < x + k; ++i) {
10                if(i >= end - count) break;
11                
12                swap(grid[i][j], grid[end - count][j]);
13                count++;
14            }
15            count = 0;
16        }
17        return grid;
18    }
19};