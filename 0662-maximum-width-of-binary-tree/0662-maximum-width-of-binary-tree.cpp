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
    void bfs(TreeNode *node, long long& maxWidth){
        queue<pair<TreeNode*, long long>> q;
        q.push({node, 0});

        while (!q.empty()){
            long long size = q.size();
            long long level_leftmost = q.front().second;
            long long level_rightmost = q.back().second;

            maxWidth = max(maxWidth, level_rightmost - level_leftmost + 1);

            for (int i = 0; i < size; ++i){
                auto [node, idx] = q.front();
                q.pop();

                long long normalized = idx - level_leftmost;

                if (node->left) q.push({node->left, 2 * normalized + 1});
                if (node->right) q.push({node->right, 2 * normalized + 2});  
            }
        }
    }

    int widthOfBinaryTree(TreeNode* root) {
        long long maxWidth = 1;

        bfs(root, maxWidth);

        return static_cast<int> (maxWidth);
    }
};