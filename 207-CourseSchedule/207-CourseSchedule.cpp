// Last updated: 12/27/2025, 3:44:54 PM
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<pair<list<int>, int>> adjacencyList(numCourses, {list<int>(), -1});

        for(auto& i : prerequisites) {
            adjacencyList[i[0]].first.push_back(i[1]);
        }

        for(int i = 0; i < numCourses; ++i) {
            // technically have to check every spot (dependency can be anywhere)
            if (adjacencyList[i].second == -1)  if (!dfs(adjacencyList, i)) return false;

        }
        
        return true;
    }

    bool dfs(vector<pair<list<int>, int>>& adjacencyList, int visited) {
        
        // memoize yay
        if(adjacencyList[visited].second == 2) return true;

        // we visited this spot this iteration
        adjacencyList[visited].second = 0;

        // dfs
        for(auto& j : adjacencyList[visited].first) {
            if(adjacencyList[j].second == 0) return false;
            if(!dfs(adjacencyList, j)) return false;
        }

        adjacencyList[visited].second = 2;

        return true;
    }

    /*
        generate a graph (adjacency list) by iterating over prereqs
        iterate through it, doing a dfs, at any point if we find a cycle its over and return false
        if iterate through everything, its allg!
    */
};