// Last updated: 1/2/2026, 5:37:22 PM
1class Solution {
2public:
3    int numOfWays(int n) {
4
5        // option 1: the row above has all 3 colors
6        // r y g can get
7        // y r y
8        // y g r
9        // y g y
10        // g r y
11
12        // if we know the row above had 3 colors than
13        // there are 4 options for the next row
14        // 2 have all 3 colors, 2 have 2/3 colors
15
16
17        // option 2: the row above has 2 colors
18        // r y r can get
19        // y r y
20        // y r g
21        // y g y
22        // g r y
23        // g r g
24
25        // if we know the row above had 3 colors than
26        // there are 5 options for the next row
27        // 2 have all 3 colors, 3 have 2/3 colors
28
29        if(n == 1) return 12;
30        int mod = 1e9 + 7;
31        
32        long long threeColor = 6, twoColor = 6;
33        
34        for(int i = 2; i <= n; i++) {
35            long long newThreeColor = (2 * twoColor + 2 * threeColor) % mod;
36            long long newTwoColor = (3 * twoColor + 2 * threeColor) % mod;
37            threeColor = newThreeColor;
38            twoColor = newTwoColor;
39        }
40        
41        return (threeColor + twoColor) % mod;       
42    }
43
44};