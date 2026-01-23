// Last updated: 1/22/2026, 5:10:36 PM
1class Solution {
2public:
3    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
4
5        vector<vector<int>> adjList(numCourses);
6        for(auto i : prerequisites) adjList[i[0]].push_back(i[1]);
7
8        vector<int> visited(numCourses, -1);
9
10        for(int i = 0; i < adjList.size(); ++i) {
11            if(visited[i] == -1) if(!dfs(adjList, visited, i)) return false;
12        }
13
14        return true;
15    }
16
17    bool dfs(vector<vector<int>>& adjList, vector<int>& visited, int next) {
18        if(visited[next] == 1) return true;
19
20        visited[next] = 0;
21
22        for(auto i : adjList[next]) {
23            if(visited[i] == 0) return false;
24            if(!dfs(adjList, visited, i)) return false;
25        }
26
27        visited[next] = 1;
28        return true;
29    }
30};