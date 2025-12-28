// Last updated: 12/28/2025, 3:17:36 PM
1class Solution {
2public:
3    int maximalSquare(vector<vector<char>>& matrix) {
4
5        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
6
7        int maxS = 0;
8
9        for(int i = 1; i <= matrix.size(); ++i)
10            for(int j = 1; j <= matrix[0].size(); ++j)
11                if(matrix[i - 1][j - 1] == '1')
12                    maxS = max(maxS, dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}));
13
14        return maxS * maxS;
15        
16    }
17};