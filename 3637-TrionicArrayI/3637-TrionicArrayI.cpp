// Last updated: 2/3/2026, 5:38:55 PM
1class Solution {
2public:
3    bool isTrionic(vector<int>& nums) {
4
5        int counter = 0;
6        int num = 0;
7        int prev = nums[0];
8
9        for(int i = 1; i < nums.size(); ++i) {
10            if(counter == 0) {
11                if(nums[i] == prev) return false;
12                else if(nums[i] > prev) { prev = nums[i]; ++num; continue; }
13                else { 
14                    if(num > 0) num = 0; else return false;
15                    ++counter; prev = nums[i];
16                }
17            }
18
19            else if(counter == 1) {
20                if(nums[i] == prev) return false;
21                else if(nums[i] < prev) { prev = nums[i]; continue; }
22                else { ++counter; prev = nums[i]; }
23            }
24
25            else {
26                if(nums[i] == prev) return false;
27                else if(nums[i] > prev) { prev = nums[i]; continue; }
28                else { ++counter; prev = nums[i]; }
29            }
30        }
31
32        return counter != 2 ? false : true;
33        
34    }
35};