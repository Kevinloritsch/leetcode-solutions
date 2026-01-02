// Last updated: 1/2/2026, 2:44:08 PM
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
29        
30        vector<vector<int>> bestNeighbors(scores.size());
31
32        for (int i = 0; i < scores.size(); ++i) {
33            int x = -1, y = -1, z = -1;
34
35            for (int j : graph[i]) {
36                if (x == -1 || scores[j] > scores[x]) {
37                    z = y;
38                    y = x;
39                    x = j;
40                } else if (y == -1 || scores[j] > scores[y]) {
41                    z = y;
42                    y = j;
43                } else if (z == -1 || scores[j] > scores[z]) {
44                    z = j;
45                }
46            }
47
48            if (x != -1) bestNeighbors[i].push_back(x);
49            if (y != -1) bestNeighbors[i].push_back(y);
50            if (z != -1) bestNeighbors[i].push_back(z);
51        }
52
53        int bestOverall = -1;
54
55        for(auto i : edges) {
56            int a = i[0];
57            int b = i[1];
58            // a and b guarenteed not equal
59
60            // nested loop is 3 things by 3 things, O(1)
61            for(auto c : bestNeighbors[a]) {
62                if(c == -1) continue;
63                for(auto d : bestNeighbors[b]) {
64                    if(d == -1) continue;
65                    if(c == d || a == c || a == d || b == c || b == d) continue;
66
67                    bestOverall = max(bestOverall, scores[a] + scores[b] + scores[c] + scores[d]);
68                }
69            }
70
71        }
72
73        return bestOverall;
74    }
75};