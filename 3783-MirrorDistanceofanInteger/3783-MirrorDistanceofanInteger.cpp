// Last updated: 4/18/2026, 4:24:11 PM
1class Solution {
2public:
3    int mirrorDistance(int n) {
4        string s = to_string(n);
5        reverse(s.begin(), s.end());
6        int n2 = stoi(s);
7
8        return abs(n - n2);
9    }
10};