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
    bool isSame(TreeNode *n1, TreeNode *n2){
        if (!n1 && !n2) return true;

        if (!n1 || !n2) return false;

        if (n1->val != n2->val) return false;

        return isSame(n1->left, n2->left) && isSame(n1->right, n2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        if (isSame(root, subRoot)) return true;

        return isSame(root->left, subRoot) || isSame(root->right, subRoot);
    }
};