// Last updated: 12/27/2025, 3:45:03 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int overallMin = prices[0];
        int maxProfit = -1;
        for(int i = 0; i < prices.size(); ++i) {
            maxProfit = std::max(maxProfit, prices[i] - overallMin);
            overallMin = std::min(overallMin, prices[i]);
        }
        return maxProfit;
    }

};