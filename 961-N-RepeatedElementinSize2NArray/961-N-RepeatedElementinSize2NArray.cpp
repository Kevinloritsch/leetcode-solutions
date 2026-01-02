// Last updated: 1/1/2026, 5:23:14 PM
1class Solution {
2public:
3    int repeatedNTimes(vector<int>& nums) {
4
5        unordered_set<int> check(0);
6
7        for(auto i : nums) {
8            if(check.find(i) != check.end()) return i;
9            check.insert(i);
10        }
11
12        return -1;
13        
14    }
15};