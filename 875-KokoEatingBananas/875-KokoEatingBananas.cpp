// Last updated: 1/29/2026, 6:55:14 PM
1class Solution {
2public:
3    int minEatingSpeed(vector<int>& piles, int h) {
4
5        int low = 1;
6        int high = INT_MAX / 2;
7        int candidate = INT_MAX;
8        int mid;
9
10        while(low <= high) {
11            mid = low + (high - low) / 2;
12
13            int r = h;
14            for(auto i : piles) {
15                if(i <= mid) --r;
16                else if (i % mid == 0) r -= (i / mid);
17                else r -= (i / mid) + 1;
18            }
19
20            if(r < 0) low = mid + 1;
21            else {
22                candidate = min(candidate, mid);
23                high = mid - 1;
24            }
25
26        }
27
28
29        return candidate;
30
31
32    }
33};
34