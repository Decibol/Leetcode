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
    void inorder(TreeNode *node, string str, vector<string>& result){
        if (!node){
            return;
        }
        
        str += to_string(node->val);

        if (!node->left && !node->right){
            result.push_back(str);
        }

        inorder(node->left, str, result);
        inorder(node->right, str, result);
    }

    int sumNumbers(TreeNode* root) {
        vector<string> result;
    
        inorder(root, "", result);

        int sum = 0;

        for (string s : result){
            sum += stoi(s);
        }

        return sum;    
    }
};