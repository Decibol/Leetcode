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
    void preorder(TreeNode *node, string& s){
        if (!node){
            s += "(#)";
            return;
        }

        s += "(" + to_string(node->val) + ")";

        preorder(node->left, s);
        preorder(node->right, s);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1 = "";
        string s2 = "";

        preorder(root, s1);
        preorder(subRoot, s2);
        
        cout << s1 << endl << s2;

        if (s1.find(s2) != string::npos){
            return true;
        }

        return false;
    }
};