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
    void dfs(TreeNode *node, int& paths, int& targetSum, long long sum){
        if (!node) return;

        sum += (long long)node->val;

        if (sum == targetSum) ++paths;

        if (node->left) dfs(node->left, paths, targetSum, sum);
        if (node->right) dfs(node->right, paths, targetSum, sum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        
        int paths = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            long long sum = 0;
            TreeNode *node = q.front();
            q.pop();

            dfs(node, paths, targetSum, sum);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return paths;
    }
};