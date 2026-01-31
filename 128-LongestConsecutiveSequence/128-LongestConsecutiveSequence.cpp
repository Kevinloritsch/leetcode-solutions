// Last updated: 1/30/2026, 5:01:19 PM
1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4
5        if(nums.size() == 0) return 0;
6
7        unordered_map<int, int> hash;
8        int best = INT_MIN;
9
10        for(auto i : nums) {
11            if(hash[i] == 0) {
12                hash[i] = hash[i + 1] + hash[i - 1] + 1;
13                
14                if(hash[i+1] != 0) hash[i+ hash[i+1]] = max(hash[i + hash[i+1]], hash[i]);
15                if(hash[i-1] != 0) hash[i - hash[i-1]] = max(hash[i - hash[i-1]], hash[i]);
16                
17                best = max(best, hash[i]);
18            }
19        }
20
21        return best;
22        
23    }
24};