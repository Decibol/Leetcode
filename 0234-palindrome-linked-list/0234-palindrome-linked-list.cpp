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
    bool isPalindrome(ListNode* head) {
        vector<int> result;

        ListNode *current = head;

        while (current != NULL){
            result.push_back(current->val);
            current = current->next;
        }

        int left = 0;
        int right = result.size() - 1;

        while(left <= right){
            if (result[left] != result[right]){
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};