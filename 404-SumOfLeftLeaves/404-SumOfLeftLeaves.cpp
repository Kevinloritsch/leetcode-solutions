// Last updated: 12/27/2025, 3:44:50 PM
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
    int sumOfLeftLeaves(TreeNode* root) {

        int sum = 0;

        queue<TreeNode*> bfs;

        bfs.push(root);

        while(!bfs.empty()) {
            TreeNode* curr = bfs.front();
            bfs.pop();

            if(curr -> left && curr -> left -> left == nullptr && curr -> left -> right == nullptr) {
                sum += curr->left->val;
            }

            if(curr->left) bfs.push(curr->left);
            if(curr->right) bfs.push(curr->right);
        }

        return sum;
        
    }
};