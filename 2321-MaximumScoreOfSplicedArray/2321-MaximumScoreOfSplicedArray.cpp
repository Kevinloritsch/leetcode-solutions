// Last updated: 1/8/2026, 5:19:03 PM
1class Solution {
2public:
3    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
4
5        int globalSum1 = 0;
6        int globalSum2 = 0;
7
8        for(int i : nums1) globalSum1 += i;
9        for(int i : nums2) globalSum2 += i;
10
11        int currSum1 = 0;
12        int currSum2 = 0;
13        int maxSum1 = 0;
14        int maxSum2 = 0;
15
16        for(int i = 0; i < nums1.size(); ++i) {
17            currSum1 = max(currSum1, 0);
18            currSum2 = max(currSum2, 0);
19
20            currSum1 += nums2[i] - nums1[i];
21            currSum2 += nums1[i] - nums2[i];
22
23            maxSum1 = max(maxSum1, currSum1);
24            maxSum2 = max(maxSum2, currSum2);
25        }
26
27        return max(globalSum1 + maxSum1, globalSum2 + maxSum2);
28
29
30    }
31};