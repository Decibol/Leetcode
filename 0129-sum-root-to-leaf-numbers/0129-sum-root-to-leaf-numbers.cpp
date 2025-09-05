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
    void inorder(TreeNode *node, int currSum, int& result){
        if (!node){
            return;
        }

        currSum = currSum * 10 + node->val;
        
        if (!node->left && !node->right){
            result += currSum;
        }


        inorder(node->left, currSum, result);
        inorder(node->right, currSum, result);
    }

    int sumNumbers(TreeNode* root) {
        int result = 0;

        inorder(root, 0, result);

        return result;  
    }
};