// Last updated: 5/28/2026, 7:52:40 PM
1class Solution {
2public:
3    int minElement(vector<int>& nums) {
4        int smallest = INT_MAX / 2;
5        int curr = 0;
6        for(auto i : nums) {
7            while(i > 0) { curr += i % 10; i /= 10; }
8            if (curr < smallest) smallest = curr;
9            curr = 0;
10        }
11
12        return smallest;        
13    }
14};