// Last updated: 12/27/2025, 3:45:24 PM
class Solution {
public:

    int jump(vector<int>& nums) {

        int numJumps = 0;
        int currBest = 0;
        int furthestReached = 0;

        for(int i = 0; i < nums.size() - 1; ++i) {
            furthestReached = std::max(furthestReached, nums[i] + i);

            if(i == currBest) {
                ++numJumps;
                currBest = furthestReached;
            }
        }return numJumps;
    }

};
