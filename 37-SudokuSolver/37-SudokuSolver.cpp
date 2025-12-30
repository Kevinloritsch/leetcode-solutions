// Last updated: 12/30/2025, 3:21:23 PM
1class Solution {
2public:
3    void solveSudoku(vector<vector<char>>& board) {
4        recursiveSolve(board, 0, 0);
5    }
6
7    bool recursiveSolve(vector<vector<char>>& board, int i, int j) {
8    if(i == 9) return true;
9    
10        int nextI = (j == 8) ? i + 1 : i;
11        int nextJ = (j == 8) ? 0 : j + 1;
12        
13        if(board[i][j] == '.') {
14            for(int k = 1; k < 10; ++k) {
15                board[i][j] = k + '0';
16                if(!currValidIndex(board, i, j, k)) continue;
17                
18                if(recursiveSolve(board, nextI, nextJ)) return true;
19            }
20            board[i][j] = '.';
21            return false;
22        }
23        
24        return recursiveSolve(board, nextI, nextJ);
25    }
26
27    bool currValidIndex(vector<vector<char>>& board, int i, int j, int val) {
28        int spot = 0;
29
30        for(int r = 0; r < 9; ++r) {
31            if(board[i][r] == '.' || j == r) continue;
32            spot = board[i][r] - '0';
33            if(spot == val) return false;
34        }
35
36        for(int c = 0; c < 9; ++c) {
37            if(board[c][j] == '.' || i == c) continue;
38            spot = board[c][j] - '0';
39            if(spot == val) return false;
40        }
41
42        for(int m = 0; m < 3; ++m) {
43            for(int n = 0; n < 3; ++n) {
44                int row = i + m - (i % 3); int col = j + n - (j % 3);
45                if(board[row][col] == '.' || (row == i && col == j)) continue;
46                spot = board[i + m - (i % 3)][j + n - (j % 3)] - '0';
47                if(spot == val) return false;
48            }
49        }
50        return true;
51    }
52};