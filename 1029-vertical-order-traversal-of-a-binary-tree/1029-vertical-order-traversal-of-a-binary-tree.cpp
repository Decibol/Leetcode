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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {{}};
        
        vector<vector<int>> result;
        map<int, vector<pair<int, int>>> verticalGroups;
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        while (!q.empty()){
            int size = q.size();

            for (int i = 0; i < size; ++i){
                auto [node, col, row] = q.front();
                q.pop();

                verticalGroups[col].push_back({row, node->val});

                if (node->left){
                    q.push({node->left, col - 1, row + 1});
                }
                if (node->right){
                    q.push({node->right, col + 1, row + 1});
                }
            }
        }

        for (auto [col, nodes] : verticalGroups){
            sort(nodes.begin(), nodes. end(), [](auto &a, auto&b){
                if (a.first == b.first){
                    return a.second < b.second;
                }

                return a.first < b.first;
            });

            vector<int> column;

            for (auto& [row, val] : nodes){
                column.push_back(val);
            }

            result.push_back(column);
        }

        return result; 
    }
};