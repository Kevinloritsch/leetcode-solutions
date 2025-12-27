// Last updated: 12/27/2025, 3:45:25 PM
class Solution {
public:
    int trap(vector<int>& height) {

        int i = 0;
        int leftMax = height[i];

        int j = height.size()-1;
        int rightMax = height[j];

        int canHold = 0;

        while(i < j) {
            if(leftMax <= rightMax) {
                canHold += (leftMax - height[i]);
                ++i;
                leftMax = max(leftMax, height[i]);
            }
            else {
                canHold += (rightMax - height[j]);
                --j;
                rightMax = max(rightMax, height[j]);
            }
        }



        return canHold;
    }
};