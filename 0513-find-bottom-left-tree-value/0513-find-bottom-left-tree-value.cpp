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
    void dfs(TreeNode *node, int depth, int& prevDepth, int& result){
        if (!node) return;

        if (depth > prevDepth){
            result = node->val;
            prevDepth = depth;
        }

        if (node->left) dfs(node->left, depth + 1, prevDepth, result);
        if (node->right) dfs(node->right, depth + 1, prevDepth, result);
    }

    int findBottomLeftValue(TreeNode* root) {
        int result = root->val;
        int depth = 0;
        int prevDepth = 0;

        dfs(root, depth, prevDepth, result);

        return result;
    }
};