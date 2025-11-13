/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        int i = 0;
        TreeNode* root = nullptr;
        stack<TreeNode*> st;

        while (i < n) {
            int depth = 0;

            while (i < n && traversal[i] == '-') {
                ++depth;
                ++i;
            }

            int val = 0;

            while (i < n && traversal[i] != '-') {
                val = val * 10 + (traversal[i] - '0');
                ++i;
            }

            TreeNode* node = new TreeNode(val);

            if (depth == 0) {
                root = node;
                st.push(node);
                continue;
            }

            while (st.size() > depth){
                st.pop();
            }

            TreeNode* parent = st.top();
            if (!parent->left){
                parent->left = node;
            }
            else {
                parent->right = node;
            }

            st.push(node);
        }

        return root;
    }
};