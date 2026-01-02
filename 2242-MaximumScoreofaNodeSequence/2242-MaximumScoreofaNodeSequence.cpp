// Last updated: 1/2/2026, 1:47:01 PM
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
31        vector<vector<int>> threeNeighbors(scores.size(), vector<int>(3, -1));
32        for(int i = 0; i < scores.size(); ++i) {
33            // score, node #
34            priority_queue<pair<int, int>> bestNeighbors;
35            for(auto j : graph[i]) { bestNeighbors.push({scores[j], j}); }
36
37            for(int k = 0; k < 3; ++k) {
38                if(bestNeighbors.empty()) break;
39                threeNeighbors[i][k] = bestNeighbors.top().second;
40                bestNeighbors.pop();
41            }
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
53            for(auto c : threeNeighbors[a]) {
54                if(c == -1) continue;
55                for(auto d : threeNeighbors[b]) {
56                    if(d == -1) continue;
57                    if(c == d || a == c || a == d || b == c || b == d) continue;
58
59                    bestOverall = max(bestOverall, scores[a] + scores[b] + scores[c] + scores[d]);
60                    // if(bestOverall == scores[a] + scores[b] + scores[c] + scores[d]) {
61                    //     cout << a << " " << scores[a] << endl;
62                    //     cout << b << " " << scores[b] << endl;
63                    //     cout << c << " " << scores[c] << endl;
64                    //     cout << d << " " << scores[d] << endl;
65                    //     cout << bestOverall << endl << endl;
66                    // }
67                }
68            }
69
70        }
71
72        return bestOverall;
73    }
74};