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
    void bfs(TreeNode *root, vector<vector<int>>& result){
        deque<TreeNode*> dq;
        dq.push_back(root);
        
        int direction = 1;

        while (!dq.empty()){
            int size = dq.size();
            vector<int> current;

            if (direction == 1){
                for (int i = 0; i < size; ++i){
                    TreeNode *node = dq.front();
                    dq.pop_front();

                    current.push_back(node->val);

                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                }
            }
            else {
                for (int i = size - 1; i >= 0; --i){
                    TreeNode *node = dq.back();
                    dq.pop_back();

                    current.push_back(node->val);

                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
            }

            result.push_back(current);
            direction *= -1;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> result;

        bfs(root, result);

        return result;
    }
};