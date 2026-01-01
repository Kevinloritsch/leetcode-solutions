// Last updated: 1/1/2026, 1:13:05 PM
1class Solution {
2public:
3    vector<int> plusOne(vector<int>& digits) {
4
5        bool allNine = false;
6
7        for(int i = digits.size() - 1; i >= 0; --i) {
8            if(digits[i] != 9) { digits[i]++; break;}
9            digits[i] = 0;
10            if(i == 0) allNine = true;
11           
12        }
13
14        if(allNine) {
15            vector<int> digitsNew = {1};
16            for(auto i : digits) digitsNew.push_back(0);
17            return digitsNew;
18        }
19
20        return digits; 
21    }
22};