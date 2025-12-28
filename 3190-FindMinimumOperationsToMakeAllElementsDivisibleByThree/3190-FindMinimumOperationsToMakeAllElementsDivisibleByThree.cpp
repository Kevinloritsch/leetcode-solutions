// Last updated: 12/27/2025, 3:44:09 PM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int counter = 0;
        for(auto i : nums) if(i % 3 != 0) counter++;
        return counter;
        
    }
};