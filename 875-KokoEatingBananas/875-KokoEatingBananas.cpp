// Last updated: 1/29/2026, 4:47:42 PM
1class Solution {
2public:
3    int minEatingSpeed(vector<int>& piles, int h) {
4
5        int low = 1;
6        int high = INT_MAX;
7        int candidate = high;
8
9        while (low <= high) {
10            int mid = low + (high - low) / 2;
11
12            long hoursLeft = h;
13            for (int i : piles) {
14                if (i <= mid) {
15                    hoursLeft -= 1;
16                }
17                else if (i % mid == 0) {
18                    hoursLeft -= i / mid;
19                }
20                else {
21                    hoursLeft -= (i / mid) + 1;
22                }
23            }
24
25            if (hoursLeft < 0) low = mid + 1;
26            else {
27                candidate = mid;
28                high = mid - 1;
29            }
30        }
31
32        return candidate;
33    }
34};
35