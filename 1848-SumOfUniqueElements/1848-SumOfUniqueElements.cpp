// Last updated: 12/28/2025, 3:18:22 PM
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {

        vector<int> count(101, 0);

        for(auto i : nums) count[i]++;

        int sum = 0;
        for(int i = 1; i < count.size(); ++i) if(count[i] == 1) sum += i;

        return sum;
        
    }
};