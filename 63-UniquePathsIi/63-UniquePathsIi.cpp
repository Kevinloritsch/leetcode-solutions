// Last updated: 12/27/2025, 3:45:21 PM
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));

        return dpUniquePaths(obstacleGrid, dp, 0, 0);
    }

    int dpUniquePaths(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int m, int n) {
        if(m > obstacleGrid.size() - 1) return 0;
        if(n > obstacleGrid[m].size() - 1) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        if(obstacleGrid[m][n] == 1) return 0;

        if(m == obstacleGrid.size() - 1 && n == obstacleGrid[m].size() - 1) return 1;


        else return dp[m][n] = dpUniquePaths(obstacleGrid, dp, m + 1, n) + dpUniquePaths(obstacleGrid, dp, m, n + 1);
        
    }
};