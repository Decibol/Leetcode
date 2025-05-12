/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        /* The logic behind the solution is that we start with 2 pointers, one each at the heads of both of 
           the lists. Eventually the pointer to the shorter list WILL reach the end before the other 
           pointer, so we will then reinitiate it to the head of the OTHER list. In this way, both pointers
           will then arrive at the intersection at the same time as THEY WILL TRAVERSE THE SAME NUMBER OF 
           NODES OVERALL.
        */
        
        if(headA == NULL || headB == NULL) return NULL;

        ListNode *p1 = headA;
        ListNode *p2 = headB;

        while(p1 != p2){

            // Traverse List 1
            if(p1 == NULL){
                p1 = headB;
            }
            else{
                p1 = p1->next;
            }

            // Traverse List B
            if(p2 == NULL){
                p2 = headA;
            }
            else{
                p2 = p2->next;
            }
        }
        return p1;
    }
};