// Last updated: 12/27/2025, 3:45:31 PM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxCalcArea = -1;
        while(i < j) {
            if(min(height[i], height[j]) * (j-i) > maxCalcArea) {
                maxCalcArea = min(height[i], height[j]) * (j-i);
            }
            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxCalcArea;
    }
};