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
    vector<long long> sums;

    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int size = q.size();
            long long sum = 0;

            for (int i = 0; i < size; ++i){
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            sums.push_back(sum);
        }
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        bfs(root);
        long long kthLargest = -1;

        sort(sums.rbegin(), sums.rend());

        for (int i = 0; i < sums.size(); ++i){
            if (i == k - 1){
                kthLargest = sums[i];
                break;
            }
        }

        return kthLargest;
    }
};