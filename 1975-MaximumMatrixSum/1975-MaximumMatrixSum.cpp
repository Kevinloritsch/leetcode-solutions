// Last updated: 1/4/2026, 6:17:09 PM
1class Solution {
2public:
3    long long maxMatrixSum(vector<vector<int>>& matrix) {
4
5        long long sum = 0;
6
7        int smallestOverall = INT_MAX;
8        int numNegative = 0;
9
10        for(auto i : matrix) {
11            for(auto j : i) {
12                smallestOverall = min(smallestOverall, abs(j));
13
14                if(j <= 0) { ++numNegative; sum += (j * -1); }
15                else sum += j;
16            }
17        }
18
19        if(numNegative % 2 == 1) sum -= (smallestOverall * 2);
20
21        return sum;
22    }
23};