// Last updated: 12/27/2025, 3:44:38 PM
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0, 0}});

        grid[0][0] = -1;

        int greatest = 0;

        while(!pq.empty()) {
            auto [i, j] = pq.top();
            pq.pop();

            grid[j.first][j.second] = -1;

            greatest = max(greatest, i);

            if(j.first == grid.size() - 1 && j.second == grid[j.first].size() - 1) break;

            if(j.first - 1 >= 0 && grid[j.first - 1][j.second] != -1) pq.push({grid[j.first - 1][j.second], {j.first - 1, j.second}});
            if(j.first + 1 <= grid.size() - 1 && grid[j.first+1][j.second] != -1) pq.push({grid[j.first + 1][j.second], {j.first + 1, j.second}});
            if(j.second - 1 >= 0 && grid[j.first][j.second - 1] != -1) pq.push({grid[j.first][j.second - 1], {j.first, j.second - 1}});
            if(j.second + 1 <= grid[j.first].size() - 1  && grid[j.first][j.second+1] != -1) pq.push({grid[j.first][j.second + 1], {j.first, j.second + 1}});
        }

        return greatest;
        
    }
};