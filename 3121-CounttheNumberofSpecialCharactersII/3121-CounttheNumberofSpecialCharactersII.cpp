// Last updated: 5/26/2026, 10:26:12 PM
1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        unordered_set<char> lower;
5        unordered_set<char> upper;
6        unordered_set<char> special;
7        vector<char> trash;
8
9        for(char c : word) {
10            if(isupper(c)) {
11                if(lower.count(c + 32) != 0) special.insert(c + 32);
12                upper.insert(c);
13
14            }
15            else {
16                if(upper.count(c - 32) != 0) { trash.push_back(c); }
17                lower.insert(c);
18            }
19        }
20
21        for(auto i : trash) {
22            if(special.count(i) != 0) special.erase(i);
23        }
24
25        return special.size();
26        
27    }
28};