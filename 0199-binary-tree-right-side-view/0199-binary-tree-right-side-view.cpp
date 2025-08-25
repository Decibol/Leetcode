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
    void dfs(TreeNode *root, int depth, vector<int>& result){
        if (!root) return;

        if (depth == result.size()){
            result.push_back(root->val);
        }

        if (root->right) dfs(root->right, depth + 1, result);
        if (root->left) dfs(root->left, depth + 1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int depth = 0;

        dfs(root, depth, result);

        return result;    
    }
};