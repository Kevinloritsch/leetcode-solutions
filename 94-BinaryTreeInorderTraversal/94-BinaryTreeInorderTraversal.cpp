// Last updated: 12/27/2025, 3:45:16 PM
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        inorderTraversal(root, arr);
        return arr;
    }
    void inorderTraversal(TreeNode* node, vector<int>& arr) {
        if(!node) return;
        inorderTraversal(node->left, arr);
        arr.push_back(node->val);
        inorderTraversal(node->right, arr);
    }
};