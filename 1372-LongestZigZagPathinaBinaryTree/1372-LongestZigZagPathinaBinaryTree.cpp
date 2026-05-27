// Last updated: 5/27/2026, 4:26:34 PM
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
13    int ans = 0;
14public:
15    int longestZigZag(TreeNode* root) {
16        zigZag(root, true, 0);
17        zigZag(root, false, 0);
18        return ans;
19    }
20
21    void zigZag(TreeNode* root, bool side, int sum) {
22        if(!root) return;
23        ans = max(ans, sum);
24        if(side) { zigZag(root->left, !side, sum + 1); zigZag(root->right, side, 1); }
25        else { zigZag(root->right, !side, sum + 1); zigZag(root->left, side, 1); }
26    }
27};