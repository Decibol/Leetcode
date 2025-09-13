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
    bool checkBST(TreeNode *root) {
        if (!root->left && !root->right) return true;

        if (!root->left){
            if (root->val < root->right->val) return true;
        }

        if (!root->right){
            if (root->val > root->left->val) return true;
        }

        if (root->val < root->right->val && root->val > root->left->val) return true;

        return checkBST(root->left) && checkBST(root->right);
    }

    int getSum(TreeNode *root, int sum, int& maxSum){
        if (!checkBST(root)) return 0;

        int left = getSum(root->left, sum, maxSum);
        int right = getSum(root->right, sum, maxSum);

        sum += left + right + root->val;

        maxSum = max(maxSum, sum);

        return sum;
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        int sum = 0;

        getSum(root, sum, maxSum);

        return maxSum;
    }
};