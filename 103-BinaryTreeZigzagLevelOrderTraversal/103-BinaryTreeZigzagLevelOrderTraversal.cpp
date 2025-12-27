// Last updated: 12/27/2025, 3:45:10 PM
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        deque<TreeNode*> bfs;
        int level = 0;

        bool zigzag = true;

        if(!root) return result;

        bfs.push_front(root);


        while(!bfs.empty()) {
            result.push_back({});
            int curr = bfs.size();
            if(zigzag) {
                while(curr > 0) {
                    TreeNode* top = bfs.front();
                    if(top) {
                        result[level].push_back(top->val);
                        if(top->left) bfs.push_back(top->left);
                        if(top->right) bfs.push_back(top->right);
                    }
                    
                    bfs.pop_front();
                    
                    --curr;

                }
            }

            else {
                while(curr > 0) {
                    TreeNode* top = bfs.back();
                    if(top) {
                        result[level].push_back(top->val);
                        if(top->right) bfs.push_front(top->right);
                        if(top->left) bfs.push_front(top->left);
                        
                    }
                    
                    bfs.pop_back();
                    
                    --curr;

                }
            }
            zigzag = !zigzag;

            ++level;
            
        }
        return result;
        
    }
};