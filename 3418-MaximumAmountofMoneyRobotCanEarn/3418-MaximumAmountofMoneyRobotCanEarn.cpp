// Last updated: 4/2/2026, 9:14:43 AM
1class Solution {
2public:
3    int maximumAmount(vector<vector<int>>& coins) {
4        vector<vector<vector<int>>> memoize(
5            coins.size(), 
6            vector<vector<int>>(coins[0].size(), vector<int>(3, INT_MIN))
7        );
8        return dpMax(coins, memoize, 0, 0, 2);
9    }
10
11    // k is how many more can neutralize
12    int dpMax(vector<vector<int>>& coins, vector<vector<vector<int>>>& memoize, int i, int j, int k) {
13        if(i > coins.size() - 1 || j > coins[i].size() - 1) return INT_MIN / 3;
14        if(i == coins.size() - 1 && j == coins[i].size() - 1) {
15            if(coins[i][j] < 0 && k > 0) return 0;
16            else return coins[i][j];
17        }
18        if(memoize[i][j][k] != INT_MIN) return memoize[i][j][k];
19
20        int v1, v2 = INT_MIN / 3;
21        v1 = max(coins[i][j] + dpMax(coins, memoize, i, j+1, k),
22                 coins[i][j] + dpMax(coins, memoize, i+1, j, k) );
23        if(coins[i][j] < 0 && k > 0)  {
24            v2 = max(dpMax(coins, memoize, i, j+1, k - 1),
25                     dpMax(coins, memoize, i+1, j, k - 1) );
26        }
27
28        return memoize[i][j][k] = max(v1, v2);
29
30    }
31};