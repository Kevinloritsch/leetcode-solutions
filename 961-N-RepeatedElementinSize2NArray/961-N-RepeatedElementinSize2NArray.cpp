// Last updated: 1/1/2026, 5:18:52 PM
1class Solution {
2public:
3    int repeatedNTimes(vector<int>& nums) {
4
5        int n = nums.size() / 2;
6
7        unordered_map<int, int> check(0);
8
9        for(auto i : nums) {
10            check[i]++;
11            if(check[i] == n) return i;
12        }
13
14        return -1;
15        
16    }
17};