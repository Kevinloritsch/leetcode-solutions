// Last updated: 5/27/2026, 2:53:30 PM
1class Solution {
2public:
3    int paintWalls(vector<int>& cost, vector<int>& time) {
4        vector<vector<int>> memo(cost.size(), vector<int>(2 * cost.size(), -1));
5
6        return dpPaintWalls(cost, time, memo, 0, 0, cost.size());
7    }
8
9    int dpPaintWalls(vector<int>& cost, vector<int>& time, vector<vector<int>>& memo, int i, int hours, int n) {
10        if(i == cost.size()) {
11            if(hours < 0) return INT_MAX / 2;
12            return 0;
13        }
14        if(hours >= n - i) return 0;
15
16        int h = hours + n;
17        if (memo[i][h] != -1) return memo[i][h];
18
19        int paid = dpPaintWalls(cost, time, memo, i + 1, hours + time[i], n) + cost[i];
20        int free = dpPaintWalls(cost, time, memo, i + 1, hours - 1, n) + 0;
21
22        return memo[i][h] = min(paid, free);
23    }
24};