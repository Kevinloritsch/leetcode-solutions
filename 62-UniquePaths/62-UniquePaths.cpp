// Last updated: 12/27/2025, 3:45:21 PM
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return dpUniquePaths(dp, 0, 0);
    }

    int dpUniquePaths(vector<vector<int>>& dp, int m, int n) {
        if(m > dp.size() - 1) return 0;
        if(n > dp[m].size() - 1) return 0;

        if (m == dp.size() - 1 && n == dp[m].size() - 1) return 1;

        if(dp[m][n] != -1) return dp[m][n];

        return dp[m][n] = dpUniquePaths(dp, m+1, n) + dpUniquePaths(dp, m, n+1);
    }
};