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
        /* SLOW AND FAST POINTER APPROACH. The logic here is that we first take a fast pointer and move
           it to the index that is on the position n+1. Then, we start moving the slow and fast pointer
           simultaenously, 1 step at a time. As soon as the fast pointer reaches NULL, we know that the 
           slow pointer will automatically be at n-1 position, i.e. just before the node to be removed.
        */
        ListNode dummy(0);
        dummy.next = head;
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;

        for(int i=0; i<=n; i++){
            fast = fast->next;
        }

        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        return dummy.next;
    }
};