// Last updated: 1/9/2026, 11:27:47 AM
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
14    int depth(TreeNode *root) {
15        if(!root) return 0;
16        return max(depth(root->left), depth(root->right)) + 1;
17    }
18
19    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
20        int depthCheck = depth(root->left) - depth(root->right);
21        // balanced, need them all for lca
22        if(depthCheck == 0) return root;
23
24        // left heavy 
25        else if (depthCheck > 0) return subtreeWithAllDeepest(root -> left);
26
27        // right heavy
28        else return subtreeWithAllDeepest(root -> right);
29    }
30};