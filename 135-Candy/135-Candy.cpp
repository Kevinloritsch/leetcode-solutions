// Last updated: 5/22/2026, 11:21:24 AM
1class Solution {
2public:
3    int candy(vector<int>& ratings) {
4        int curr = 1, prev = ratings[0], total = 0, numDesc = 0;
5
6        auto flushDesc = [&]() {
7            if (numDesc > 0) {
8                if (curr > numDesc) { total += numDesc * (numDesc + 1) / 2; }
9                else { total += (numDesc + 1) * (numDesc + 2) / 2 - curr; }
10                curr = 1; numDesc = 0;
11            }
12        };
13
14        for (auto i : ratings) {
15            if (i == prev)      { flushDesc(); total += 1; curr = 1; }
16            else if (i < prev)  { ++numDesc; prev = i; }
17            else                { flushDesc(); total += ++curr; prev = i; }
18        }
19        flushDesc();
20
21        return total;
22    }
23};