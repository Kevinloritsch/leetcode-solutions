// Last updated: 12/27/2025, 3:45:01 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int best = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;

        return max(best, maxPathSumHelp(root));
    }

    int maxPathSumHelp(TreeNode* root) {
        if(!root) return INT_MIN / 3;

        int lhs = maxPathSumHelp(root->left);
        int rhs = maxPathSumHelp(root->right);

        int bestKids = max(lhs, rhs);
        int bestOneSide = max(root->val + lhs, root->val + rhs);

        best = max(best, lhs + rhs + root->val);
        best = max(best, bestKids);

        return max(root->val, bestOneSide);
    }


};