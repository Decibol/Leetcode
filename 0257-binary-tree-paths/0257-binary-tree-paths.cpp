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
    void dfs(TreeNode *node, string str, vector<string>& result){
        if (str == ""){
            str += to_string(node->val);
        } else {
            str += "->" + to_string(node->val);
        }

        if (!node->left && !node->right){
            result.push_back(str);
            return; 
        }

        if(node->left){
            dfs(node->left, str, result);
        } 
        
        if (node->right){
            dfs(node->right, str, result);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string s = "";

        dfs(root, s, result);

        return result;
    }
};