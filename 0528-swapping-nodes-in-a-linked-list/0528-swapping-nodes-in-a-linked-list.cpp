/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp = head;
        vector<int> nums;

        while (temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }

        int n = nums.size();

        swap(nums[k - 1], nums[n - k]);

        ListNode *newHead = new ListNode(nums[0]);
        ListNode *current = newHead;

        for (int i = 1; i < nums.size(); ++i){
            current->next = new ListNode(nums[i]);
            current = current->next;
        }

        return newHead;
    }
};