// Last updated: 4/20/2026, 1:33:49 PM
1class Solution {
2public:
3    bool xorGame(vector<int>& nums) {
4        int xorCount = 0;
5        for(auto i : nums) xorCount = xorCount ^ i;
6        if(xorCount == 0) return true;
7
8        return 1 - nums.size() % 2;
9    }
10};
11
12
13/*
14win by default
151, 2, 3
161, 10, 11
172, 2
180
19
200, 1
210, 1
221
23
241, 1, 2
251, 1, 10
261, 2
27
28
29*/