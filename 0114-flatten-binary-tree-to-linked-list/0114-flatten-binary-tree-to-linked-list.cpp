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
    void preorder(TreeNode *node, vector<TreeNode*>& result){
        if (!node) return;

        result.push_back(node);
        preorder(node->left, result);
        preorder(node->right, result);    
    }

    void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> nodes;

        preorder(root, nodes);

        for (int i = 0; i < nodes.size() - 1; ++i){
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }

        nodes.back()->left = nullptr;
        nodes.back()->right = nullptr;
    }
};