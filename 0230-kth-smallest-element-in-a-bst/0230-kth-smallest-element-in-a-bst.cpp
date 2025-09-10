class Solution {
public:
    void dfs(TreeNode *root, int& k, int& count, int& result) {
        if (!root) return;

        dfs(root->left, k, count, result);

        if (count >= k) return;

        ++count;
        if (count == k) {
            result = root->val;
            return;
        }

        dfs(root->right, k, count, result);
    }

    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        int count = 0;

        dfs(root, k, count, result);

        return result;
    }
};
