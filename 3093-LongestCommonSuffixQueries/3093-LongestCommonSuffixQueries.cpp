// Last updated: 5/28/2026, 1:33:41 PM
1class Node {
2public:
3    bool isEnd;
4    std::vector<Node*> children;
5    int best;
6    Node() : isEnd(false), children(26, nullptr), best(-1) {}
7
8    ~Node() {
9        for (Node* child : children) {
10            if (child != nullptr) {
11                delete child;
12            }
13        }
14    }
15};
16
17class Solution {
18public:
19    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
20
21        ios_base::sync_with_stdio(false);
22        cin.tie(NULL);
23
24        // iterate through wordsContainers, insert to trie with reversed word
25        // for each query, we iterate through the suffix
26        // bfs downward to find the shortest length
27        // throw in a unordered map with each word and their position, if i tie, O(1) figure out which occured earlier
28
29        Node* root = new Node();
30        for(int i = 0; i < wordsContainer.size(); ++i) {
31            const string& s = wordsContainer[i];
32            Node* temp = root;
33            for(int c = s.length() - 1; c >= 0; --c) {
34                char charac = s[c];
35                if(!temp->children[charac - 97]) {
36                    temp->children[charac - 97] = new Node();
37                }
38                temp = temp->children[charac - 97];
39                if (temp->best == -1) {
40                    temp->best = i;
41                } else {
42                    int prev = temp->best;
43                    int prevLen = wordsContainer[prev].size();
44                    int curLen  = wordsContainer[i].size();
45                    if (curLen < prevLen)
46                        temp->best = i;
47                }
48                if(c == 0) {
49                    if(temp->isEnd) break;
50                    temp->isEnd = true;
51                }
52            }
53        }
54
55        int lengthOfShortest = INT_MAX / 2;
56        int posOfShortest = -1;
57
58        for(int i = 0; i < wordsContainer.size(); ++i) {
59            if(wordsContainer[i].length() < lengthOfShortest) {
60                // will be the first occurence of the shortest length
61                lengthOfShortest = wordsContainer[i].length();
62                posOfShortest = i;
63            }
64        }
65
66        vector<int> ans;
67
68        for (auto q : wordsQuery) {
69            Node* temp = root;
70            bool noMatch = false;
71
72            for (int c = q.length() - 1; c >= 0; --c) {
73                char charac = q[c];
74                if (!temp->children[charac - 97] && c == q.length() - 1) {
75                    ans.push_back(posOfShortest);
76                    noMatch = true;
77                    break;
78                }
79                else if(!temp->children[charac - 97]) break;
80                temp = temp->children[charac - 97];
81            }
82            if (noMatch) continue;
83            if(temp->best == -1) ans.push_back(posOfShortest);
84            else ans.push_back(temp->best);
85        }
86        delete root;
87
88        return ans;        
89    }
90};