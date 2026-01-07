// Last updated: 1/6/2026, 4:49:14 PM
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
14    int maxProduct(TreeNode* root) {
15        TreeNode* prefixRoot = new TreeNode();
16        buildTree(prefixRoot, root);
17
18        long long best = LONG_MIN;
19
20        int totalSum = prefixRoot -> val;
21
22        stack<pair<TreeNode*, TreeNode*>> dfs;
23        dfs.push({root, prefixRoot});
24
25        while(!dfs.empty()) {
26            auto front = dfs.top();
27            dfs.pop();
28
29            if (front.first -> left) {
30                long long leftVal = front.second -> left -> val;
31                long long product = leftVal * (totalSum - leftVal);
32                best = best >= product ? best : product;
33                dfs.push({front.first -> left, front.second -> left});
34            }
35            if(front.first -> right) {
36                long long rightVal = front.second -> right -> val;
37                long long product = rightVal * (totalSum - rightVal);
38                best = best >= product ? best : product;
39                dfs.push({front.first -> right, front.second -> right});
40            }
41        }
42
43        return best % 1000000007;
44    }
45
46    int buildTree(TreeNode* rootPrefix, TreeNode* root) {
47        if(!root) return 0;
48        if(root -> left) rootPrefix -> left = new TreeNode();
49        if(root -> right) rootPrefix -> right = new TreeNode();
50
51        int left = buildTree(rootPrefix -> left, root -> left);
52        int right = buildTree(rootPrefix -> right, root -> right);
53        
54        rootPrefix -> val  = left + right + root -> val;
55        
56        return left + right + root -> val;
57    }
58};