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

struct Info{
    bool isBST;
    int minVal;
    int maxVal;
    int sum;

    Info() : isBST(true), minVal(INT_MAX), maxVal(INT_MIN), sum(0) {}
};

class Solution {
public:
    Info* dfs(TreeNode *root, int& result){
        if (!root){
            Info *current = new Info();
            return current;
        }

        Info *left = dfs(root->left, result);
        Info *right = dfs(root->right, result);

        Info *current = new Info();

        current->minVal = min(root->val, left->minVal);
        current->maxVal = max(root->val, right->maxVal);
        current->sum = left->sum + right->sum + root->val;
        current->isBST = left->isBST && right->isBST && root->val > left->maxVal && root->val < right->minVal;

        if (current->isBST){
            result = max(result, current->sum);
        }

        return current; 
    } 

    int maxSumBST(TreeNode* root) {
        int result = 0;

        dfs(root, result);

        return result;
    }
};