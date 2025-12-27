// Last updated: 12/27/2025, 3:44:55 PM
class Solution {
public:
    int rob(vector<int>& nums) {
        int prevRob = 0;
        int maxRob = 0;

        for (int curValue : nums) {
            int temporary = max(maxRob, prevRob + curValue);
            prevRob = maxRob;
            maxRob = temporary;
        }

        return maxRob;   
    }

    
};