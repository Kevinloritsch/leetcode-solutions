// Last updated: 4/5/2026, 11:28:41 PM
1class Solution {
2public:
3    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
4
5        sort(offers.begin(), offers.end(),
6            [](vector<int>& a, vector<int>&b) { return a[1] < b[1]; });
7
8        int result = 0;
9        vector<int> memoize(n, 0);
10
11        // memoize holds all n houses
12        // memoize[i] is the best profit for the first i houses
13        
14        for(auto offer : offers) {
15
16            // check if we jumped ahead a bunch
17            if(result > 0) {
18                for(int i = offer[1]; i >= 0 && memoize[i] == 0; --i) memoize[i] = result;
19            }
20
21            // what happened before this chunk
22            int prev = 0;
23            if(offer[0] > 0) prev = memoize[offer[0] - 1];
24
25            result = max(result, prev + offer[2]);
26            memoize[offer[1]] = result;
27        }
28
29        return result;
30        
31    }
32};