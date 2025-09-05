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
private:
    unordered_map<int, int> inorderMap;

    TreeNode *build(vector<int>& preorder, int& preorderIndex, int inorderLeft, int inorderRight){
        if (inorderLeft > inorderRight) return nullptr;

        int rootValue = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootValue);

        int inorderRootIndex = inorderMap[rootValue];

        root->left = build(preorder, preorderIndex, inorderLeft, inorderRootIndex - 1);
        root->right = build(preorder, preorderIndex, inorderRootIndex + 1, inorderRight);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        for (int i = 0; i < n; ++i){
            inorderMap[inorder[i]] = i;
        }

        int preorderIndex = 0;
        int inorderLeft = 0;
        int inorderRight = n - 1;

        return build(preorder, preorderIndex, inorderLeft, inorderRight);
    }
};