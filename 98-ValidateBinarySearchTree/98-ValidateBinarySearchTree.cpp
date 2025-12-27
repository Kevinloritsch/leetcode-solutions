// Last updated: 12/27/2025, 3:45:15 PM
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
    bool isValidBST(TreeNode* root) {
        return isValidBSTCheck(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBSTCheck(TreeNode* node, long small, long large) {
        if(!node) return true;
        if((node->val <= small) || (node->val >= large)) return false;

        return (isValidBSTCheck(node->left, small, node->val) && isValidBSTCheck(node->right, node->val, large));
    }

};