// Last updated: 1/8/2026, 2:07:40 PM
1class Solution {
2public:
3    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
4
5        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
6
7        int best = INT_MIN;
8
9        for(int i = nums1.size() - 1; i >= 0; --i) {
10            best = max(nums1[i] * nums2.back(), best);
11            dp[i][nums2.size() - 1] = best;
12        }
13
14        best = INT_MIN;
15
16        for(int i = nums2.size() - 1; i >= 0; --i) {
17            best = max(nums2[i] * nums1.back(), best);
18            dp[nums1.size() - 1][i] = best;
19        }
20
21        int curr;
22        for(int i = nums1.size() - 2; i >= 0; --i) {
23            for(int j = nums2.size() - 2; j >= 0; --j) {
24                // get three surronding
25                curr = max(dp[i+1][j], dp[i][j+1]);
26                curr = max(curr, dp[i+1][j+1]);
27                curr = max(curr, dp[i+1][j+1] + nums1[i] * nums2[j]);
28                curr = max(curr, nums1[i] * nums2[j]);
29                dp[i][j] = curr;
30            }
31        }
32        return dp[0][0];
33    }
34};