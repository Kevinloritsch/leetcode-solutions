// Last updated: 1/5/2026, 7:08:45 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int maxLevelSum(TreeNode* root) {
15
16        queue<TreeNode*> bfs;
17
18        bfs.push(root);
19
20        int curr;
21        int maxSum = INT_MIN;
22        int level = 1;
23        int bestLevel = -1;
24        int currSum;
25
26        while(!bfs.empty()) {
27            curr = bfs.size();
28            currSum = 0;
29            for(int i = 0; i < curr; ++i) {
30                TreeNode* front = bfs.front();
31                bfs.pop();
32                currSum += front->val;
33                if(front -> left) bfs.push(front -> left);
34                if(front -> right) bfs.push(front -> right);
35                
36            }
37            if(currSum > maxSum) {
38                bestLevel = level;
39                maxSum = currSum;
40            }
41            ++level;
42        }
43
44        return bestLevel;
45        
46    }
47};