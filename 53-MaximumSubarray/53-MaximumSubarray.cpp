// Last updated: 1/8/2026, 3:08:18 PM
1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4
5        int currSum = nums[0];
6        int maxSum = nums[0];
7
8        for(int i = 1; i < nums.size(); ++i) {
9            currSum = max(currSum + nums[i], nums[i]);
10            maxSum = max(maxSum, currSum);
11        }
12        return maxSum;
13        
14    }
15};