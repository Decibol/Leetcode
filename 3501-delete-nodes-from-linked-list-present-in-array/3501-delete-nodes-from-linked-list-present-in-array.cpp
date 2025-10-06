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
private:
    void removeNode(ListNode *node){
        ListNode *temp = node->next;
        node->next = temp->next;
    }

public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> nodesToRemove(nums.begin(), nums.end());

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *current = dummy;

        while (current->next){
            if (nodesToRemove.count(current->next->val)){
                removeNode(current);
            }
            else {
                current = current->next;
            }
        }

        return dummy->next;
    }
};