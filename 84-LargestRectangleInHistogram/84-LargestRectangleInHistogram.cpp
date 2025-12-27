// Last updated: 12/27/2025, 3:45:17 PM
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> maintainer;
        int maxArea = -1;

        heights.push_back(0);

        for(int i = 0; i < heights.size(); i++) {
            while(!maintainer.empty() && heights[maintainer.top()] >= heights[i]) {
                int h = heights[maintainer.top()];
                maintainer.pop();

                int prevIndex = maintainer.empty() ? -1 : maintainer.top();
                int curr = h * (i - prevIndex - 1);
                maxArea = max(maxArea, curr);
            }
            maintainer.push(i);

        }

        return maxArea;

        
    }
};

/*

x x
xxx
212



     x
x    x
x  x x
xx xxx
xx xxx
420325

     x
   x x
 x x x
 xxx x
 xxxxx
 xxxxx
xxxxxx
xxxxxxx
36574810

*/