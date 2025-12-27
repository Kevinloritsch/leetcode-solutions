// Last updated: 12/27/2025, 3:45:23 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currSum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < nums.size(); ++i) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
        
    }
};