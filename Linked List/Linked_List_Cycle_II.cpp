/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Floyd's Tortoise and Hare Algorithm
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) break;
        }
        
        if (!(fast && fast->next)) return NULL;

        while(head != slow){
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};