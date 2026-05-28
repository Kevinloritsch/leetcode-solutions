// Last updated: 5/28/2026, 1:32:24 PM
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
21        // iterate through wordsContainers, insert to trie with reversed word
22        // for each query, we iterate through the suffix
23        // bfs downward to find the shortest length
24        // throw in a unordered map with each word and their position, if i tie, O(1) figure out which occured earlier
25
26        Node* root = new Node();
27        for(int i = 0; i < wordsContainer.size(); ++i) {
28            const string& s = wordsContainer[i];
29            Node* temp = root;
30            for(int c = s.length() - 1; c >= 0; --c) {
31                char charac = s[c];
32                if(!temp->children[charac - 97]) {
33                    temp->children[charac - 97] = new Node();
34                }
35                temp = temp->children[charac - 97];
36                if (temp->best == -1) {
37                    temp->best = i;
38                } else {
39                    int prev = temp->best;
40                    int prevLen = wordsContainer[prev].size();
41                    int curLen  = wordsContainer[i].size();
42                    if (curLen < prevLen)
43                        temp->best = i;
44                }
45                if(c == 0) {
46                    if(temp->isEnd) break;
47                    temp->isEnd = true;
48                }
49            }
50        }
51
52        int lengthOfShortest = INT_MAX / 2;
53        int posOfShortest = -1;
54
55        for(int i = 0; i < wordsContainer.size(); ++i) {
56            if(wordsContainer[i].length() < lengthOfShortest) {
57                // will be the first occurence of the shortest length
58                lengthOfShortest = wordsContainer[i].length();
59                posOfShortest = i;
60            }
61        }
62
63        vector<int> ans;
64
65        for (auto q : wordsQuery) {
66            Node* temp = root;
67            bool noMatch = false;
68
69            for (int c = q.length() - 1; c >= 0; --c) {
70                char charac = q[c];
71                if (!temp->children[charac - 97] && c == q.length() - 1) {
72                    ans.push_back(posOfShortest);
73                    noMatch = true;
74                    break;
75                }
76                else if(!temp->children[charac - 97]) break;
77                temp = temp->children[charac - 97];
78            }
79            if (noMatch) continue;
80            if(temp->best == -1) ans.push_back(posOfShortest);
81            else ans.push_back(temp->best);
82        }
83        delete root;
84
85        return ans;        
86    }
87};