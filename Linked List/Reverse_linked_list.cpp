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
    ListNode* reverseList(ListNode* head) {
        ListNode *current = head; // We create two pointers, current and previous
        ListNode *previous = NULL; // Initialize current as the head, and previous as NULL
        while(current){
            ListNode *newTemp = current->next; /* Assign the next node of current to a temp variable, 
                                                  so that it isn't lost when we break the link */
            
            current->next = previous;  // now make the current's next pointer point to the previous node
            previous = current; /* Move the pointers so that the previous node is now the current node,
                                   and the current node is now the next node */
            current = newTemp;
        }
        return previous;
    }
};