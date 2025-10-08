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
    bool check(TreeNode *node, long long maxVal, long long minVal){
        if (!node) return true;

        if (node->val <= minVal || node->val >= maxVal) return false;

        return check(node->left, node->val, minVal) && check(node->right, maxVal, node->val);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MAX, LLONG_MIN);
    }
};