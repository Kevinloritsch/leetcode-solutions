// Last updated: 1/13/2026, 3:31:29 PM
1class Solution {
2public:
3    double separateSquares(vector<vector<int>>& squares) {
4        long double minm = 0;
5        long double max = INT_MAX;
6        long double mid;
7        long double underArea = 0;
8        long double aboveArea = 0;
9        long double candidateY = LDBL_MAX;
10
11        while(minm + 1e-5 <= max) {
12            mid = minm + (max - minm) / 2;
13            underArea = 0;
14            aboveArea = 0;
15
16            for(auto& i : squares) {
17                if(i[1] < mid && i[1] + i[2] > mid) {
18                    underArea += 1.0L * (mid - i[1]) * (mid - i[1]);
19                    aboveArea += 1.0L * (i[1] + i[2] - mid) * (i[1] + i[2] - mid);
20                }
21                else if(i[1] < mid) { underArea += 1.0L *i[2] * i[2]; }
22                else { aboveArea += 1.0L * i[2] * i[2]; }
23            }
24            if(abs(underArea - aboveArea) < 1e-6) { candidateY = min(mid, candidateY); max = mid; }
25            else if(underArea < aboveArea) minm = mid;
26            else max = mid;
27        }
28        return candidateY != LDBL_MAX ? candidateY : mid;
29    }
30};