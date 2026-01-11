// Last updated: 1/11/2026, 3:10:01 PM
1class Solution {
2public:
3    int largestRectangleArea(vector<int>& heights) {
4
5        stack<int> maintainer;
6        int maxArea = -1;
7
8        // free extra check at the end that doesnt mess with the data teehee
9        heights.push_back(0);
10
11        for(int i = 0; i < heights.size(); i++) {
12            // we only push if we're the definite biggest thing
13            while(!maintainer.empty() && heights[maintainer.top()] >= heights[i]) {
14                // get the current biggest thing then throw it away
15                int h = heights[maintainer.top()];
16                maintainer.pop();
17
18                // since its strictly increasing, we get that current biggest thing, and see how 
19                // many rectangles we can compute using it
20                // if its the strictly largest, the rectangle will have width 1
21                // when we go to the one before it, we now get a width of 2
22                // using the height of the one before it
23                int prevIndex = maintainer.empty() ? -1 : maintainer.top();
24                int curr = h * (i - prevIndex - 1);
25                maxArea = max(maxArea, curr);
26            }
27            maintainer.push(i);
28
29        }
30
31        return maxArea;
32    }
33};
34
35/*
36
37x x
38xxx
39212
40
41
42
43     x
44x    x
45x  x x
46xx xxx
47xx xxx
48420325
49
50     x
51   x x
52 x x x
53 xxx x
54 xxxxx
55 xxxxx
56xxxxxx
57xxxxxxx
5836574810
59
60*/