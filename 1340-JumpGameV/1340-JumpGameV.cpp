// Last updated: 5/24/2026, 4:12:35 PM
1class Solution {
2public:
3    int maxJumps(vector<int>& arr, int d) {
4        vector<int> visited(arr.size(), -1);
5
6        int best = INT_MIN;
7        for(int i = 0; i < arr.size(); ++i) {
8            best = max(best, dfs(arr, visited, i, d));
9        }
10
11        return best;
12        
13    }
14
15    int dfs(vector<int>& arr, vector<int>& visited, int i, int d) {
16        if(visited[i] != -1) return visited[i];
17
18        visited[i] = 1;
19
20        int check = 0;
21        for(int j = i - 1; j >= 0 && check < d; --j) {
22            if (arr[j] >= arr[i]) break; 
23            visited[i] = max(visited[i], dfs(arr, visited, j, d) + 1);
24            ++check;
25        }
26        check = 0;
27        for(int j = i + 1; j < arr.size() && check < d; ++j) {
28            if (arr[j] >= arr[i]) break; 
29            visited[i] = max(visited[i], dfs(arr, visited, j, d) + 1);
30            ++check;
31        }
32
33        return visited[i];
34    }
35};