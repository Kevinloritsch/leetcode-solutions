// Last updated: 12/27/2025, 5:29:32 PM
1class Solution {
2public:
3    int sumOfUnique(vector<int>& nums) {
4
5        vector<int> count(101, 0);
6
7        for(auto i : nums) count[i]++;
8
9        int sum = 0;
10        for(int i = 1; i < count.size(); ++i) if(count[i] == 1) sum += i;
11
12        return sum;
13        
14    }
15};