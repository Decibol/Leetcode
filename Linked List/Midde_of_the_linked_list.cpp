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
    ListNode* middleNode(ListNode* head) {
        // SLOW TURTLE AND FAST HARE APPROACH
        ListNode *slow = head; // Declare a slow pointer
        ListNode *fast = head; // Declare a fast pointer. The slow and fast pointers both start at head.
        
        while(fast != NULL && fast->next != NULL){ /* We HAVE to check the fast != NULL condition because
                                                      otherwise the program would CRASH */
            
            slow = slow->next; // Move the slow pointer by only 1 step
            fast = fast->next->next; // Move the fast pointer by 2 steps

        }
        return slow;
    }
};