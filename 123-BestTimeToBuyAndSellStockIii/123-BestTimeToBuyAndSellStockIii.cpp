// Last updated: 12/27/2025, 3:45:02 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, -1));
        return dpMaxProfit(prices, dp, 0, 0);
    }

    int dpMaxProfit(vector<int>& prices, vector<vector<int>>& dp, int i, int num) {
        if(num >= 4) return 0;
        if(i >= prices.size()) return 0;
        if(dp[i][num] != -1) return dp[i][num];

        if(num % 2 == 0) return dp[i][num] = max(dpMaxProfit(prices, dp, i + 1, num), dpMaxProfit(prices, dp, i + 1, num+1) - prices[i]);

        else return dp[i][num] = max(dpMaxProfit(prices, dp, i + 1, num), dpMaxProfit(prices, dp, i + 1, num+1) + prices[i]);

        
    }
};