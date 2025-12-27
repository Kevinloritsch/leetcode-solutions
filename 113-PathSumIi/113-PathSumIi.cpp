// Last updated: 12/27/2025, 3:45:06 PM
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> currPath;

        pathSum(root, targetSum, allPaths, currPath);

        return allPaths;
    }

    void pathSum(TreeNode* node, int targetSum, vector<vector<int>>& allPaths, vector<int>& currPath) {
        if(!node) {
            return;
        }
        if(!node->left && !node->right && targetSum - node->val == 0) {
            currPath.push_back(node->val);
            allPaths.push_back(currPath);
            currPath.pop_back();
            return;
        }

        currPath.push_back(node->val);

        pathSum(node->left, targetSum - node->val, allPaths, currPath);
        pathSum(node->right, targetSum - node->val, allPaths, currPath);

        currPath.pop_back();

    }
};