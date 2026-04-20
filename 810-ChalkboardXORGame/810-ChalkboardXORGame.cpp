// Last updated: 4/20/2026, 1:33:42 PM
1class Solution {
2public:
3    bool xorGame(vector<int>& nums) {
4        int xorCount = 0;
5        for(auto i : nums) xorCount = xorCount ^ i;
6        if(xorCount == 0) return true;
7        cout << xorCount;
8
9        return 1 - nums.size() % 2;
10    }
11};
12
13
14/*
15win by default
161, 2, 3
171, 10, 11
182, 2
190
20
210, 1
220, 1
231
24
251, 1, 2
261, 1, 10
271, 2
28
29
30*/