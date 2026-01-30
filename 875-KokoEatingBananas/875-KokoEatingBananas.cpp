// Last updated: 1/29/2026, 5:06:35 PM
1class Solution {
2public:
3    int minEatingSpeed(vector<int>& piles, int h) {
4
5        int low = 1;
6        int high = INT_MAX / 2;
7        int candidate = INT_MAX;
8        int mid;
9
10        while(high >= low) {
11            mid = low + (high - low) / 2;
12
13            int r = h;
14
15            for(auto i : piles) {
16                if(i <= mid) --r;
17                else if (i % mid == 0) r -= (i / mid);
18                else r -= (i / mid) + 1;
19            }
20
21            if(r < 0) low = mid + 1;
22            else {
23                candidate = min(candidate, mid);
24                high = mid - 1;
25            }
26        }
27
28        return candidate;
29    }
30};
31