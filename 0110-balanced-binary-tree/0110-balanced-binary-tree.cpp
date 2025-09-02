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
    int getHeight(TreeNode *node){
        if (!node) return 0;

        int leftHeight = getHeight(node->left);
        if (leftHeight == -1) return -1;

        int rightHeight = getHeight(node->right);
        if (rightHeight == -1) return -1;

        int difference = abs(leftHeight - rightHeight);

        if (difference > 1) return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        int height = getHeight(root);

        return height != -1;
    }
};