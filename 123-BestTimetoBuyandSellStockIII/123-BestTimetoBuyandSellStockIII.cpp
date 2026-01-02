// Last updated: 1/2/2026, 12:11:13 PM
1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4
5        int oneBuy = INT_MAX;
6        int oneBuyOneSell = 0;
7        int twoBuy = INT_MAX;
8        int twoBuyTwoSell = 0;
9
10        for(auto i : prices) {
11            oneBuy = min(oneBuy, i);
12            oneBuyOneSell = max(oneBuyOneSell, i - oneBuy);
13            twoBuy = min(twoBuy, i - oneBuyOneSell);
14            twoBuyTwoSell = max(twoBuyTwoSell, i - twoBuy);
15        }
16
17        return twoBuyTwoSell;
18        
19    }
20        
21};