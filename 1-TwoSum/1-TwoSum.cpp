// Last updated: 12/27/2025, 3:45:35 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> hash;

        vector<int> toReturn(2, -1);

        for(int i = 0; i < nums.size(); ++i) {
            if(hash.count(target - nums[i]) == 0) {
                hash[nums[i]] = i;
            }
            else {
                toReturn[0] = hash[target - nums[i]];

                toReturn[1] = i;
                break;
            }
        }

        return toReturn;
    }
};