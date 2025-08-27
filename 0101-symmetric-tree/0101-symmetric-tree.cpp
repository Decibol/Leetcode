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
    void dfs(TreeNode *root, int depth, vector<int>& result, int direction){
        if (!root){
            result.push_back(INT_MAX);
            return;
        }

        if (direction == 0){
            result.push_back(root->val);
            dfs(root->left, depth + 1, result, direction);

            if (depth >= 1){
                dfs(root->right, depth + 1, result, direction);
            }

        }
        else if (direction == 1){
            result.push_back(root->val);
            dfs(root->right, depth + 1, result, direction);

            if (depth >= 1){
                dfs(root->left, depth + 1, result, direction);
            }
        }
    }

    bool isSymmetric(TreeNode* root) {
        vector<int> leftSubtree;
        vector<int> rightSubtree;

        dfs(root, 0, leftSubtree, 0);
        dfs(root, 0, rightSubtree, 1);

        return leftSubtree == rightSubtree;
    }
};