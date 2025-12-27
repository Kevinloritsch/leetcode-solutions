// Last updated: 12/27/2025, 3:45:00 PM
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map<Node*, Node*> status;

        return dfs(node, status);
    }

    Node* dfs(Node* nodeOriginal, unordered_map<Node*, Node*>& status) {
        if (status.count(nodeOriginal)) return status[nodeOriginal];

        Node* newNode = new Node(nodeOriginal->val);
        status[nodeOriginal] = newNode;

        for(auto i : nodeOriginal->neighbors) {         
            newNode->neighbors.push_back(dfs(i, status));
        }

        return newNode;
    }
};