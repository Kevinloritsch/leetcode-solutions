// Last updated: 1/22/2026, 2:49:03 PM
1class Solution {
2public:
3    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
4
5        vector<vector<int>> adjacencyList(numCourses);
6
7        for(auto& i : prerequisites) adjacencyList[i[0]].push_back(i[1]);
8
9        vector<int> visited(numCourses, -1);
10
11        for(int i = 0; i < numCourses; ++i) {
12            if (visited[i] == -1)  if (!dfs(adjacencyList, visited, i)) return false;
13        }
14        
15        return true;
16    }
17
18    bool dfs(vector<vector<int>>& adjacencyList, vector<int>& visited, int next) {
19        if(visited[next] == 1) return true;
20
21        visited[next] = 0;
22
23        for(auto& j : adjacencyList[next]) {
24            if(visited[j] == 0) return false;
25            if(!dfs(adjacencyList, visited, j)) return false;
26        }
27
28        visited[next] = 1;
29
30        return true;
31    }
32};