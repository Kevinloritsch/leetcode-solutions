// Last updated: 1/3/2026, 4:22:24 PM
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
19            // don't want square root, odd number of divisors
20            for(int j = 2; j * j <= i; ++j) {
21                if(i % j == 0) {
22                    if(j * j == i) numDivisors++;
23                    else {
24                        numDivisors += 2;
25                        if(numDivisors == 6) break;
26                        divisorSum += j + (i / j); 
27                    }  
28                }
29            }
30            if(numDivisors == 4) { map[i] = divisorSum; total += divisorSum; }
31            else map[i] = -1;
32        }
33
34        return total;
35    }
36};