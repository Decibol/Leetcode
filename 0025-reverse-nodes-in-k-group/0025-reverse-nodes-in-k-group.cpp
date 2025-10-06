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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prevGroupEnd = dummy;
        ListNode *current = head;

        while (true){
            ListNode *node = current;
            
            for (int i = 0; i < k; ++i){
                if (!node) return dummy->next;
                node = node->next;
            }

            ListNode *prev = nullptr;
            ListNode *tail = current;

            for (int i = 0; i < k; ++i){
                ListNode *temp = current->next;
                current->next = prev;
                prev = current;
                current = temp;
            }

            prevGroupEnd->next = prev;
            tail->next = current;
            prevGroupEnd = tail;
        }

        return dummy->next;
    }
};