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
    void dfs(TreeNode *node, int level, int& result){
        result = max(result, level + 1);

        if (node->left) dfs(node->left, level + 1, result);
        if (node->right) dfs(node->right, level + 1, result);
    }

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        
        int level = 0;
        int result = 0;

        dfs(root, level, result);

        return result;
    }
};