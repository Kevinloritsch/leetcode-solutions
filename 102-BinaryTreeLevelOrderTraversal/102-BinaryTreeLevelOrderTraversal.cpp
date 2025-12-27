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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> bfs;
        int level = 0;

        if(!root) return result;

        bfs.push(root);

        

        while(!bfs.empty()) {
            result.push_back({});
            int curr = bfs.size();
            while(curr > 0) {
                TreeNode* top = bfs.front();
                if(top) {
                    result[level].push_back(top->val);
                    if(top->left) bfs.push(top->left);
                    if(top->right) bfs.push(top->right);
                }
                
                bfs.pop();
                
                --curr;

            }
            ++level;
            
        }
        return result;
    }
    
};