// Last updated: 6/1/2026, 11:06:16 AM
1class Solution {
2public:
3    int findMaxForm(vector<string>& strs, int m, int n) {
4        vector<vector<vector<int>>> memo(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
5
6        return numCombo(strs, memo, m, n, 0, 0, 0);
7    }
8
9    int numCombo(vector<string>& strs, vector<vector<vector<int>>>& memo, int m, int n, int i, int mCount, int nCount) {
10        if(mCount > m) return -1;
11        if(nCount > n) return -1;
12        if(i >= strs.size()) return 0;
13        if(memo[i][mCount][nCount] != -1) return memo[i][mCount][nCount];
14
15        string j = strs[i];
16        int nums0inJ = 0;
17        int nums1inJ = 0;
18        for(auto c : j) {
19            if(c == '0') ++nums0inJ;
20            else ++nums1inJ;
21        }
22
23        int without = numCombo(strs, memo, m, n, i + 1, mCount, nCount);
24        int with = numCombo(strs, memo, m, n, i + 1, mCount + nums0inJ, nCount + nums1inJ) + 1;
25
26
27        return memo[i][mCount][nCount] = max(without, with);
28    }
29};