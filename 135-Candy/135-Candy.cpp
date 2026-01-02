// Last updated: 1/2/2026, 1:14:58 PM
1class Solution {
2public:
3    int candy(vector<int>& ratings) {
4
5        int curr = 1;
6        int prev = ratings[0];
7        int total = 0;
8        int numDesc = 0;
9
10        for(auto i : ratings) {
11            if(i == prev) { 
12                if(numDesc > 0) {
13                    if(curr > numDesc) { curr = 1; total += (numDesc * (numDesc + 1) / 2); }
14                    else {
15                        total -= curr;
16                        curr = 1;
17                        total += ((numDesc + 1) * (numDesc + 2) / 2); 
18                    }
19                }
20                total += 1; numDesc = 0; curr = 1;
21            }
22
23            else if(i < prev) { ++numDesc; prev = i; }
24
25            else {
26                if(numDesc > 0) {
27                    if(curr > numDesc) { curr = 1; total += (numDesc * (numDesc + 1) / 2); }
28                    else {
29                        total -= curr;
30                        curr = 1;
31                        total += ((numDesc + 1) * (numDesc + 2) / 2); 
32                    }
33                }
34                ++curr; total += curr; numDesc = 0; prev = i;
35            }
36
37        }
38        if(numDesc > 0) {
39            if(curr > numDesc) { curr = 1; total += (numDesc * (numDesc + 1) / 2); }
40            else {
41                total -= curr;
42                curr = 1;
43                total += ((numDesc + 1) * (numDesc + 2) / 2); 
44            }
45        }
46
47        return total;
48        
49    }
50};