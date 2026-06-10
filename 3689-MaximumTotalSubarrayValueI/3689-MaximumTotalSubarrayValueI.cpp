// Last updated: 6/10/2026, 12:04:39 PM
1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        int max = INT_MIN;
5        int min = INT_MAX;
6        for(auto i : nums) {
7            if(i > max) max = i;
8            if(i < min) min = i;
9        }
10
11        return (long long)(max - min) * k;
12        
13    }
14};