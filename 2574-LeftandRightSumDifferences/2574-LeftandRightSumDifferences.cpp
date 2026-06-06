// Last updated: 6/6/2026, 11:01:38 AM
1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        int sum = 0;
5        for(auto i : nums) sum += i;
6        vector<int> ans;
7        int right = 0;
8        for(int i : nums) {
9            cout << i << endl;
10            sum -= i;
11            ans.push_back(abs(right - sum));
12            right += i;
13        }
14        return ans;        
15    }
16};