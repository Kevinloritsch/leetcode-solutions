// Last updated: 12/27/2025, 3:44:25 PM
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {

        if(nums.size() == 1 && k % 2 == 1) return -1;

        else if(k < nums.size()) {
            int top = INT_MIN;
            for(int i = 0; i < k - 1; ++i) {
                top = max(top, nums[i]);
            }
            top = max(top, nums[k]);

            return top;
        }


        // else
        int top = INT_MIN;
        for(int i = 0; i < nums.size() && i < k - 1; ++i) {
            top = max(top, nums[i]);
        }

        return top;
        
    }
};