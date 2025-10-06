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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> result;

        for (int i = 0; i < lists.size(); ++i){
            ListNode* current = lists[i];

            while (current){
                result.push_back(current->val);
                current = current->next;
            }
        }

        if (result.empty()) return nullptr;

        sort(result.begin(), result.end());

        ListNode *head = new ListNode(result[0]);
        ListNode *current = head;

        for (int i = 1; i < result.size(); ++i){
            ListNode *temp = new ListNode(result[i]);
            current->next = temp;
            current = current->next;
        }
        
        return head;
    }
};