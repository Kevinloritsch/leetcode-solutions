// Last updated: 5/26/2026, 2:03:46 PM
1class Solution {
2public:
3    vector<long long> maximumEvenSplit(long long finalSum) {
4        vector<long long> ans;
5        if(finalSum % 2 == 1) return ans;
6
7        int guess = 2;
8        while(finalSum > 0){
9            ans.push_back(guess);
10            finalSum -= guess;
11            guess += 2;
12        }
13
14        if(finalSum == 0) return ans;
15
16        finalSum *= -1;
17        auto it = lower_bound(ans.begin(), ans.end(), finalSum);
18        ans.erase(it);
19
20        return ans;
21        
22    }
23};