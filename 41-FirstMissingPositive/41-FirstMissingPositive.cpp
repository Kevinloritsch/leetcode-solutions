// Last updated: 12/27/2025, 3:45:26 PM
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> numCount;

        for(int i : nums) if(i > 0) numCount.insert(i);

        for(int i = 1; i <= nums.size() + 1; ++i) {
            if(!numCount.count(i)) return i;
        }

        return nums.size() + 1;
    }
};