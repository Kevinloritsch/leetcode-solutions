// Last updated: 12/27/2025, 3:45:12 PM
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        return isSymmetricHelper(root->left, root->right);
        
    }

    bool isSymmetricHelper(TreeNode* lhs, TreeNode* rhs) {
        if(!lhs && !rhs) return true;
        if((!lhs && rhs) || (lhs && !rhs)) return false;
        if (lhs -> val != rhs -> val) return false;

        if(!isSymmetricHelper(lhs->left, rhs->right)) return false;

        if(!isSymmetricHelper(lhs->right, rhs->left)) return false;

        return true;

    }
};