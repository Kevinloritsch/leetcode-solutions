// Last updated: 12/27/2025, 3:44:52 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string compress = "";
        serialize(root, compress);
        return compress;
    }

    void serialize(TreeNode* node, string& compress) {
        if(!node) {
            compress += "null,";
            return;
        }
        compress += to_string(node->val) + ",";
        serialize(node->left, compress);
        serialize(node->right, compress);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // TreeNode* root = nullptr;
        int i = 0;
        
        return deserialize(data, i);
    }

    TreeNode* deserialize(string& data, int& i) {
        string currWord = "";
        while (i < data.size() && data[i] != ',') {
            currWord += data[i];
            i++;
        }
        i++;

        if(currWord == "null") return nullptr;

        
        cout << currWord << endl;
        TreeNode* node = new TreeNode(stoi(currWord));
        node->left = deserialize(data, i);
        node->right = deserialize(data, i);
        return node;
 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));