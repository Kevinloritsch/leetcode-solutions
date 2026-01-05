// Last updated: 1/5/2026, 1:29:13 PM
1class Solution {
2public:
3    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
4
5        int globalSum1 = 0;
6        int globalSum2 = 0;
7
8        for(auto i : nums1) globalSum1 += i;
9
10        for(auto i : nums2) globalSum2 += i;
11
12        // diff sum
13        int maxDiffOne = 0;
14        int maxDiffTwo = 0;
15        int currDiffOne = 0;
16        int currDiffTwo = 0;
17
18        for(int i = 0; i < nums1.size(); ++i) {
19            currDiffOne = max(currDiffOne, 0);
20            currDiffTwo = max(currDiffTwo, 0);
21
22            currDiffOne += nums2[i] - nums1[i];
23            currDiffTwo += nums1[i] - nums2[i];
24
25            maxDiffOne = max(maxDiffOne, currDiffOne);
26            maxDiffTwo = max(maxDiffTwo, currDiffTwo);
27        }
28
29
30        return max(globalSum1 + maxDiffOne, globalSum2 + maxDiffTwo);
31    }
32};