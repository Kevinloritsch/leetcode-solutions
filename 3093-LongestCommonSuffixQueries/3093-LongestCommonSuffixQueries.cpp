// Last updated: 5/28/2026, 1:35:18 PM
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
20        ios_base::sync_with_stdio(false);
21        cin.tie(NULL);
22
23        // iterate through wordsContainers, insert to trie with reversed word
24        // for each query, we iterate through the suffix
25        // bfs downward to find the shortest length
26        // throw in a unordered map with each word and their position, if i tie, O(1) figure out which occured earlier
27
28        Node* root = new Node();
29        for(int i = 0; i < wordsContainer.size(); ++i) {
30            const string& s = wordsContainer[i];
31            Node* temp = root;
32            for(int c = s.length() - 1; c >= 0; --c) {
33                char charac = s[c];
34                if(!temp->children[charac - 97]) {
35                    temp->children[charac - 97] = new Node();
36                }
37                temp = temp->children[charac - 97];
38                if (temp->best == -1) {
39                    temp->best = i;
40                } else {
41                    int prev = temp->best;
42                    int prevLen = wordsContainer[prev].size();
43                    int curLen  = wordsContainer[i].size();
44                    if (curLen < prevLen)
45                        temp->best = i;
46                }
47                if(c == 0) {
48                    if(temp->isEnd) break;
49                    temp->isEnd = true;
50                }
51            }
52        }
53
54        int lengthOfShortest = INT_MAX / 2;
55        int posOfShortest = -1;
56
57        for(int i = 0; i < wordsContainer.size(); ++i) {
58            if(wordsContainer[i].length() < lengthOfShortest) {
59                // will be the first occurence of the shortest length
60                lengthOfShortest = wordsContainer[i].length();
61                posOfShortest = i;
62            }
63        }
64
65        vector<int> ans;
66
67        for (auto& q : wordsQuery) {
68            Node* temp = root;
69            bool noMatch = false;
70
71            for (int c = q.length() - 1; c >= 0; --c) {
72                char charac = q[c];
73                if (!temp->children[charac - 97] && c == q.length() - 1) {
74                    ans.push_back(posOfShortest);
75                    noMatch = true;
76                    break;
77                }
78                else if(!temp->children[charac - 97]) break;
79                temp = temp->children[charac - 97];
80            }
81            if (noMatch) continue;
82            if(temp->best == -1) ans.push_back(posOfShortest);
83            else ans.push_back(temp->best);
84        }
85        delete root;
86
87        return ans;        
88    }
89};