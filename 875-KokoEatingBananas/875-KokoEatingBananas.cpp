// Last updated: 1/29/2026, 4:48:40 PM
1class Solution {
2public:
3    int minEatingSpeed(vector<int>& piles, int h) {
4
5        int low = 1;
6        int high = INT_MAX / 2;
7        int candidate = high;
8
9        while (low <= high) {
10            int mid = low + (high - low) / 2;
11
12            long hoursLeft = h;
13            for (int i : piles) {
14                if (i <= mid) hoursLeft -= 1;
15                else if (i % mid == 0) hoursLeft -= i / mid;
16                else hoursLeft -= (i / mid) + 1;
17            }
18
19            if (hoursLeft < 0) low = mid + 1;
20            else {
21                candidate = mid;
22                high = mid - 1;
23            }
24        }
25
26        return candidate;
27    }
28};
29