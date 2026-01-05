// Last updated: 1/4/2026, 6:18:34 PM
1class Solution {
2public:
3    long long maxMatrixSum(vector<vector<int>>& matrix) {
4
5        long long sum = 0;
6
7        int smallestOverall = INT_MAX;
8        int numNegative = 0;
9
10        for (const auto& row : matrix) {
11            for (int x : row) {
12                int ax = x < 0 ? -x : x;
13                sum += ax;
14                smallestOverall = min(smallestOverall, ax);
15                if (x < 0) numNegative++;
16            }
17        }
18
19        if(numNegative % 2 == 1) sum -= (smallestOverall * 2);
20
21        return sum;
22    }
23};