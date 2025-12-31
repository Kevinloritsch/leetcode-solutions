// Last updated: 12/31/2025, 3:29:41 PM
1class Solution {
2public:
3    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
4
5        // must be strictly less
6        vector<vector<int>> isValidUntil(row + 1, vector<int>(col + 1, row * col + 1));
7
8        int day = 1;
9        for(auto i : cells) { isValidUntil[i[0]][i[1]] = day; ++day; }
10
11        int max = cells.size();
12        int min = 0;
13
14        int mid = min + (max - min) / 2;
15        int result = 0;
16
17        while(max >= min) {
18            cout << mid << endl;
19            if(dfsHelper(isValidUntil, mid, row, col)) {
20                result = mid;
21                min = mid + 1;
22            }
23            else {
24                max = mid - 1;
25            }
26
27            mid = min + (max - min) / 2;
28            
29        }
30
31        return result;
32    }
33
34    bool dfsHelper(vector<vector<int>>& isValidUntil, int day, int row, int col) {
35
36        vector<vector<bool>> visited(row + 1, vector<bool>(col + 1, false));
37
38        for(int j = 1; j <= col; ++j) {
39            if(dfs(isValidUntil, visited, day, 1, j, row, col)) return true;
40        }
41        return false;
42
43    }
44
45    bool dfs(vector<vector<int>>& isValidUntil, vector<vector<bool>>& visited,
46            int day, int r, int c, int row, int col) {
47        if(r < 1 || r > row || c < 1 || c > col) return false;
48        if(visited[r][c] || isValidUntil[r][c] <= day) return false;
49
50        if(r == row) return true;
51
52        visited[r][c] = true;
53
54        return dfs(isValidUntil, visited, day, r + 1, c, row, col) ||
55               dfs(isValidUntil, visited, day, r - 1, c, row, col) ||
56               dfs(isValidUntil, visited, day, r, c + 1, row, col) ||
57               dfs(isValidUntil, visited, day, r, c - 1, row, col);
58    }
59};