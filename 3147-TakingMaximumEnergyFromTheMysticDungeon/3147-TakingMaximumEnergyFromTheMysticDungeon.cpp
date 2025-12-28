// Last updated: 12/27/2025, 3:44:07 PM
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        vector<int> dp(energy.size(), INT_MIN);

        int best = INT_MIN / 3;

        for(int i = 0; i < dp.size(); ++i) {
            best = std::max(best, dpCall(energy, dp, i, k));
        }

        return best;
    }

    int dpCall(vector<int>& energy, vector<int>& dp, int i, int k) {
        if(i > energy.size() - 1) return 0;
        if(dp[i] != INT_MIN) return dp[i];
        return dp[i] = energy[i] + dpCall(energy, dp, i+k, k);
    }
};