// Last updated: 8/18/2026, 11:51:36 PM
1class Solution {
2public:
3    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
4
5        std::sort(reservedSeats.begin(), reservedSeats.end());
6
7        bool oneIsOpen = true, twoIsOpen = true, threeIsOpen = true;
8        int currRow = 1;
9        int total = 0;
10
11        for(auto i : reservedSeats) {
12            if(i[0] > currRow) {
13                if(oneIsOpen && threeIsOpen) total += 2;
14                else if(oneIsOpen || twoIsOpen || threeIsOpen) total++;
15
16                total += 2 * (i[0] - currRow - 1);
17
18                oneIsOpen = true; twoIsOpen = true; threeIsOpen = true;
19                currRow = i[0];
20            }
21
22            if(i[1] == 2 || i[1] == 3) oneIsOpen = false;
23            else if(i[1] == 4 || i[1] == 5) { oneIsOpen = false; twoIsOpen = false; }
24            else if(i[1] == 6 || i[1] == 7) { threeIsOpen = false; twoIsOpen = false; }
25            if(i[1] == 8 || i[1] == 9) threeIsOpen = false;
26        }
27        if(oneIsOpen && threeIsOpen) total += 2;
28        else if(oneIsOpen || twoIsOpen || threeIsOpen) total++;
29
30        total += 2 * (n - currRow);
31
32        return total;
33        
34    }
35};