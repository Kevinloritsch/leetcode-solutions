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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> bfs;

        int depth = 1;
        int rowSize;
        TreeNode* top;

        bfs.push(root);

        while(!bfs.empty()) {

            rowSize = bfs.size();

            for(int i = 0; i < rowSize; ++i) {
                top = bfs.front();
                bfs.pop();

                if(!top->left && !top->right) return depth;

                if(top->left) bfs.push(top->left);
                if(top->right) bfs.push(top->right);
            }
            depth++;

        }
        return depth;
    }
};