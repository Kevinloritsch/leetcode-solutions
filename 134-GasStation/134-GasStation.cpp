// Last updated: 1/9/2026, 12:03:07 PM
1class Solution {
2public:
3    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
4        
5        int totalGas = 0;
6        int totalCost = 0;
7        int currGas = 0;
8        int start = 0;
9
10        for(int i = 0; i < gas.size(); ++i) {
11            totalGas += gas[i]; totalCost += cost[i];
12
13            currGas += gas[i] - cost[i];
14            if(currGas < 0) { start = i + 1; currGas = 0; }
15        }
16
17        if(totalCost > totalGas) return -1;
18        return start;
19    }
20};