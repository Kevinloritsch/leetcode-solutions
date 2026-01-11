// Last updated: 1/11/2026, 11:23:40 AM
1class Solution {
2public:
3    int maximalRectangle(vector<vector<char>>& matrix) {
4        if(!matrix.size()) return 0;
5        int best = 0;
6        for(int i = 0; i < matrix.size(); i++) 
7            for(int j = 0; j < matrix[i].size(); j++) 
8                for(int row = i, colLen = matrix[i].size(), col; row < matrix.size() && matrix[row][j] == '1'; row++) {
9                    for(col = j; col < matrix[i].size() && matrix[row][col] == '1'; col++);
10                    colLen = min(colLen, col - j);
11                    best = max(best, (row-i+1) * colLen);
12                }
13            
14        return best;
15    }
16};