// Last updated: 1/9/2026, 11:49:49 AM
1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4
5        int result = 0;
6
7        for(auto i : nums) {
8            result ^= i;
9        }
10
11        return result;
12    }
13};