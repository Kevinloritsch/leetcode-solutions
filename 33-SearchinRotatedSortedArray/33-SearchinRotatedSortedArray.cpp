// Last updated: 5/22/2026, 11:43:23 AM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4
5        if(nums.size() == 1) return nums[0] == target ? 0 : -1;
6
7        int low = 0;
8        int high = nums.size() - 1;
9
10        while(low <= high) {
11            int mid = low + (high - low) / 2;
12            if(nums[mid] == target) return mid;
13
14            if(nums[low] <= nums[mid]) {
15                if(nums[low] <= target && nums[mid] >= target) high = mid -1;
16                else low = mid + 1;
17            }
18            else {
19                if(nums[high] >= target && nums[mid] <= target) low = mid + 1;
20                else high = mid - 1;
21            }
22        }
23
24        return -1;
25        
26    }
27
28};