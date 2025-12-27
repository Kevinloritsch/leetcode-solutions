// Last updated: 12/27/2025, 3:44:41 PM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto & node : times) {
            graph[node[0]].push_back({node[1], node[2]});
        }

        // distance and me
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, INT_MAX);

        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()) {
            auto [distance, me] = pq.top();
            pq.pop();

            if(distance > dist[me]) continue;

            for(auto & [neighbor, weight] : graph[me]) {
                if(dist[me] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[me] + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }

        }

        int toReturn = -1;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            toReturn = max(toReturn, dist[i]);
        }
        return toReturn;
    }
};