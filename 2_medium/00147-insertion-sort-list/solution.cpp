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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->val > curr->val) {
                curr = curr->next;
            } else {
                ListNode* prev = dummy;
                ListNode* b = curr->next;
                ListNode* c = b->next;

                while (prev->next->val < b->val) {
                    prev = prev->next;
                }
                b->next = prev->next;
                prev->next = b;
                curr->next = c;
            }
        }

        ListNode* new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};
