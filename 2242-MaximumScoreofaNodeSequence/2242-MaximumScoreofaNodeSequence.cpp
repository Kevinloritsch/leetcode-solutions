// Last updated: 1/2/2026, 2:41:42 PM
1class Solution {
2public:
3    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
4
5        // if we visit each edge, we compare 2 nodes together automatically
6        // that means i only need to look at 2 other nodes
7        // if i precompute each node
8        // i can look through all the edges of that node and derive its 3 best neighbors
9        // the reason i need 3 is in the case of
10        // a -- b (the edge i'm checking is between and b)
11        // a's best neighbors are b, and c and d
12        // b's best neighbords are a, and c and d
13        // the top two from a are gonna be b and c, but we can't use b
14        // the top two from b are gonna be b and c, which we can't use
15        // have to recompute to find d
16
17        // now we look at each pair, and find the top two not being used of 6 values
18        // just maximize that score
19
20        vector<vector<int>> graph(scores.size());
21
22        for(auto i : edges) {
23            graph[i[0]].push_back(i[1]);
24            graph[i[1]].push_back(i[0]);
25        }
26
27        // precompute
28        // we can hash these out
29        // and find them using a pq... so we go through each edge, push them all, then pop 3
30        
31        vector<vector<int>> bestNeighbors(scores.size());
32        for(int i = 0; i < scores.size(); ++i) {
33            // node #
34            for(auto j : graph[i]) { bestNeighbors[i].push_back(j); }
35
36            sort(bestNeighbors[i].begin(), bestNeighbors[i].end(),
37            [&](int a, int b) {
38                return scores[a] > scores[b];
39            });
40
41            if (bestNeighbors[i].size() > 3) bestNeighbors[i].resize(3);
42        }
43
44
45        int bestOverall = -1;
46
47        for(auto i : edges) {
48            int a = i[0];
49            int b = i[1];
50            // a and b guarenteed not equal
51
52            // nested loop is 3 things by 3 things, O(1)
53            for(auto c : bestNeighbors[a]) {
54                if(c == -1) continue;
55                for(auto d : bestNeighbors[b]) {
56                    if(d == -1) continue;
57                    if(c == d || a == c || a == d || b == c || b == d) continue;
58
59                    bestOverall = max(bestOverall, scores[a] + scores[b] + scores[c] + scores[d]);
60                }
61            }
62
63        }
64
65        return bestOverall;
66    }
67};