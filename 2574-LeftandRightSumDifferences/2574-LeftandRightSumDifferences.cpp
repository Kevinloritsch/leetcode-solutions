// Last updated: 6/6/2026, 11:01:55 AM
1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        int sum = 0;
5        for(auto i : nums) sum += i;
6        vector<int> ans;
7        int right = 0;
8        for(int i : nums) {
9            sum -= i;
10            ans.push_back(abs(right - sum));
11            right += i;
12        }
13        return ans;        
14    }
15};