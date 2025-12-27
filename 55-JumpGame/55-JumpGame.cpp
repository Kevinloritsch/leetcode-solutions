// Last updated: 12/27/2025, 3:45:22 PM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // vector<bool> memoize(nums.size(), true);
        // return dpCanJump(nums, memoize, 0);

        int target = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; --i) {
            if(i + nums[i] >= target) target = i;
        }
        return target == 0;
    }

    // bool dpCanJump(vector<int>& nums, vector<bool>& memoize, int position) {
    //     if(position >= nums.size() - 1) return true;
    //     if(!memoize[position]) return false;

    //     int currPos = nums[position];
    //     while(currPos > 0) {
    //         if(dpCanJump(nums, memoize, position + currPos)) return true;
    //         currPos--;

    //     }
    //     return memoize[position] = false;
    // }
};