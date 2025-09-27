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
private:
    unordered_map<Node*, Node*> clones;

public:
    Node *dfs(Node *node){
        Node* copy =  new Node(node->val);
        clones[node] = copy;

        for (auto neighbor : node->neighbors){
            if (clones.find(neighbor) != clones.end()){
                copy->neighbors.push_back(clones[neighbor]);
            }
            else {
                copy->neighbors.push_back(dfs(neighbor));
            }
        }

        return copy;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        return dfs(node);
    }
};