// Last updated: 12/27/2025, 3:45:08 PM
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
    bool isBalanced(TreeNode* root) {
        return isBalancedCheck(root);
    }

    bool isBalancedCheck(TreeNode* node) {
        if(!node) return true;
        if(abs(height(node->left) - height(node->right)) > 1) return false;

        return isBalancedCheck(node->left) && isBalancedCheck(node->right);
    }

    int height(TreeNode* node) {
        if(!node) return -1;
        return max(height(node->left), height(node->right)) + 1;
    }
};