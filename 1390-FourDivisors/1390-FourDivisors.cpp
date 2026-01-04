// Last updated: 1/3/2026, 4:23:13 PM
1class Solution {
2public:
3    int sumFourDivisors(vector<int>& nums) {
4
5        unordered_map<int, int> map;
6
7        int total = 0;
8
9        for(auto i : nums) {
10            if(i < 6) continue;
11
12            if (map.find(i) != map.end()) {
13                if(map[i] != -1) total += map[i];
14                continue;
15            }
16
17            int numDivisors = 2;
18            int divisorSum = 1 + i;
19            for(int j = 2; j * j <= i; ++j) {
20                if(i % j == 0) {
21                    if(j * j == i) numDivisors++;
22                    else {
23                        numDivisors += 2;
24                        if(numDivisors == 6) break;
25                        divisorSum += j + (i / j); 
26                    }  
27                }
28            }
29            if(numDivisors == 4) { map[i] = divisorSum; total += divisorSum; }
30            else map[i] = -1;
31        }
32
33        return total;
34    }
35};