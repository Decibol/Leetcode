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
    unordered_map<int, int> inorderMap;

    TreeNode *build(vector<int>& postorder, int& postorderIndex, int inorderLeft, int inorderRight){
        if (inorderLeft > inorderRight) return nullptr;

        int rootValue = postorder[postorderIndex--];
        TreeNode *root = new TreeNode(rootValue);

        int inorderRootIndex = inorderMap[rootValue];

        root->right = build(postorder, postorderIndex, inorderRootIndex + 1, inorderRight);
        root->left = build(postorder, postorderIndex, inorderLeft, inorderRootIndex - 1);


        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex = postorder.size() - 1;

        for (int i = 0; i < inorder.size(); ++i){
            inorderMap[inorder[i]] = i;
        }

        return build(postorder, postorderIndex, 0, inorder.size() - 1);
    }
};