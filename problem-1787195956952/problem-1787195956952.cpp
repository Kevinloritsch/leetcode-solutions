// Last updated: 8/19/2026, 8:19:16 PM
1class Solution {
2public:
3    vector<int> resultArray(vector<int>& nums) {
4
5        vector<int> arr1, arr2;
6
7        arr1.push_back(nums[0]);
8        int onePtr = nums[0];
9        arr2.push_back(nums[1]);
10        int twoPtr = nums[1];
11
12        for(int i = 2; i < nums.size(); ++i) {
13            if(onePtr > twoPtr) { onePtr = nums[i]; arr1.push_back(nums[i]); }
14            else { twoPtr = nums[i]; arr2.push_back(nums[i]); }
15        }
16        for(auto i : arr2) arr1.push_back(i);
17
18        return arr1;
19        
20    }
21};