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
    void dfs(TreeNode *root, int depth, int& maxDepth, int& result){
        if (!root) return;
        if (depth > maxDepth){
            result = root->val;
            maxDepth = depth;
        }

        if (root->left) dfs(root->left, depth + 1, maxDepth, result);
        if (root->right) dfs(root->right, depth + 1, maxDepth, result);
    }

    int findBottomLeftValue(TreeNode* root) {
        int depth = 0;
        int maxDepth = 0;
        int result = root->val;

        dfs(root, depth, maxDepth, result);

        return result;
    }
};