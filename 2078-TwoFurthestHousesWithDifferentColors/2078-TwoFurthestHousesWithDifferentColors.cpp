// Last updated: 4/20/2026, 2:01:07 PM
1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        int best = 0;
5        for(int i = 0; i < colors.size(); ++i) {
6            for(int j = i + 1; j < colors.size(); ++j) {
7                if(colors[i] != colors[j]) best = max(best, abs(j - i));
8            }
9        }
10        return best;
11    }
12};