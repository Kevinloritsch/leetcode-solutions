// Last updated: 12/27/2025, 3:44:53 PM
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        int prev1 = 0, prev2 = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            int temp = prev1;
            prev1 = max(prev2 + nums[i], prev1);
            prev2 = temp;
        }
        int store = prev1;

        prev1 = 0, prev2 = 0;
        for (int i = 1; i < nums.size(); ++i) {
            int temp = prev1;
            prev1 = max(prev2 + nums[i], prev1);
            prev2 = temp;
        }

        return max(store, prev1);
    }
};