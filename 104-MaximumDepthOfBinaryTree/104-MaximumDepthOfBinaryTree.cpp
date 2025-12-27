// Last updated: 12/27/2025, 3:45:09 PM
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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*> bfs;

        bfs.push(root);
        int level = 0;
        int curr = bfs.size();

        while(!bfs.empty()) {
            ++level;
            while(curr > 0) {
                // TreeNode* top = ;
                
                if(bfs.front()->left) bfs.push(bfs.front()->left);
                if(bfs.front()->right) bfs.push(bfs.front()->right);
                
                bfs.pop();
                --curr;
            }
            curr = bfs.size();
        }
        return level;
        
    }
};