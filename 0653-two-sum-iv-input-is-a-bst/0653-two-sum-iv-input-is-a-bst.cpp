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
    void dfs(TreeNode *root, vector<int>& result){
        if (!root) return;

        result.push_back(root->val);
        dfs(root->left, result);
        dfs(root->right, result);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> result;
        dfs(root, result);

        unordered_map<int, int> pair;

        for (int i = 0; i < result.size(); ++i){
            int complement = k - result[i];

            if (pair.find(complement) != pair.end()){
                return true;
            }

            pair[result[i]] = i;
        }


        return false;
    }
};