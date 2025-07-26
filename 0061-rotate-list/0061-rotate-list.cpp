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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return {};

        ListNode *left = head;
        ListNode *right = head;
        ListNode *current = head;

        int length = 0;

        while (current){
            current = current->next;
            length++;
        }
        
        k = k % length;
        if (k == 0) return head;

        for (int i = 0; i < k; ++i){
            right = right->next;
        }

        while (right->next){
            left = left->next;
            right = right->next;
        }

        ListNode *newHead = left->next;
        left->next = nullptr;
        right->next = head;

        return newHead;
    }
};