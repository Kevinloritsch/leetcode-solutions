// Last updated: 1/11/2026, 5:49:00 PM
1class Solution {
2public:
3    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
4        int total = 0, xDistance = 0, yDistance = 0, min = 0, max = 0;
5
6        int prevX = points[0][0];
7        int prevY = points[0][1];
8
9        for(auto point : points) {
10            xDistance = abs(prevX - point[0]);
11            yDistance = abs(prevY - point[1]);
12
13            if(xDistance < yDistance) { min = xDistance; max = yDistance; }
14            else { min = yDistance; max = xDistance; }
15            prevX = point[0];
16            prevY = point[1];
17
18            total += min + (max - min);
19        }
20
21        return total;
22    }
23};