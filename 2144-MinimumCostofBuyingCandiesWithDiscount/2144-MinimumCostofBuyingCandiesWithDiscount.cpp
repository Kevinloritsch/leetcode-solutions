// Last updated: 6/1/2026, 10:53:27 AM
1class Solution {
2public:
3    int minimumCost(vector<int>& cost) {
4        std::sort(cost.begin(), cost.end());
5
6        int sum = 0;
7        int num = 1;
8
9        for(int i = cost.size() - 1; i >= 0; --i) {
10            if(num == 3) {
11                num = 1;
12                continue;
13            }
14            sum += cost[i];
15            num++;
16        }  
17        return sum;
18        
19    }
20};