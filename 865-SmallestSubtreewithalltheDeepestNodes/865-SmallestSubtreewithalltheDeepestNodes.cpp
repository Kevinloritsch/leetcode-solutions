// Last updated: 1/9/2026, 11:22:50 AM
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
15        return !root ? 0 : max(depth(root->left), depth(root->right)) + 1;
16    }
17
18    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
19        int d = depth(root->left) - depth(root->right);
20        return d == 0 ? root : subtreeWithAllDeepest(d > 0 ? root->left : root->right);
21    }
22};