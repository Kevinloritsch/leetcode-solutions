// Last updated: 1/11/2026, 5:51:38 PM
1class Solution {
2public:
3    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
4        int total = 0, xDistance = 0, yDistance = 0;
5
6        int prevX = points[0][0];
7        int prevY = points[0][1];
8
9        for(auto point : points) {
10            xDistance = abs(prevX - point[0]);
11            yDistance = abs(prevY - point[1]);
12
13            prevX = point[0];
14            prevY = point[1];
15
16            total += max(xDistance, yDistance);
17        }
18
19        return total;
20    }
21};