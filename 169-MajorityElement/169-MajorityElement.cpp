// Last updated: 12/27/2025, 3:44:59 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> numCount;

        int size = (nums.size() + 1) / 2;

        for(auto& i : nums) if(++numCount[i] == size) return i;

        return -1;
    }
};