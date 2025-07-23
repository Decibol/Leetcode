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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;

        int count = 0;

        for (int i = 0; i <= n; ++i){
            fast = fast->next;
        }

        while (fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *newTemp = slow->next;
        slow->next = slow->next->next;
        delete newTemp;

        return dummy.next;
    }
};