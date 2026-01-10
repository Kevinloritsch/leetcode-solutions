// Last updated: 1/9/2026, 6:18:33 PM
1class Solution {
2public:
3    int minimumDeleteSum(string s1, string s2) {
4        vector<vector<int>> dp (s1.length(), vector<int>(s2.length(), -1));
5        return(sum(s1, s2, s1.length() - 1, s2.length() - 1, dp));
6    }
7
8    int sum(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
9        if(i < 0 && j < 0) return 0;
10
11        if(i < 0) {
12            int jSum = 0;
13            for(j; j >= 0; --j) jSum += s2[j];
14            return jSum;
15        }
16        if(j < 0) {
17            int iSum = 0;
18            for(i; i >= 0; --i) iSum += s1[i];
19            return iSum;
20        }
21
22        if(dp[i][j] != -1) return dp[i][j];
23
24
25        if(s1[i] == s2[j]) return sum(s1, s2, i - 1, j - 1, dp);
26
27        int poss1 = sum(s1, s2, i - 1, j, dp) + int(s1[i]);
28        int poss2 = sum(s1, s2, i, j - 1, dp) + int(s2[j]);
29        int poss3 = sum(s1, s2, i - 1, j - 1, dp) + int(s1[i]) + int(s2[j]);
30        return dp[i][j] = min(poss1, min(poss2, poss3));
31    }
32};