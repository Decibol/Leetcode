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
    void dfs(TreeNode *node, int level, vector<int>& result){
        if (!node) return;

        if (level == result.size()){
            result.push_back(node->val);
        }

        if (node->right) dfs(node->right, level + 1, result);
        if (node->left) dfs(node->left, level + 1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int level = 0;

        dfs(root, level, result);

        return result;
    }
};