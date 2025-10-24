class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res_dummy = new ListNode(0);
        ListNode* res_prev = res_dummy;

        int offset = 0;
        while (true) {

            int num1 = 0;
            if (l1 != nullptr) {
                num1 = l1->val;
                l1 = l1->next;
            }

            int num2 = 0;
            if (l2 != nullptr) {
                num2 = l2->val;
                l2 = l2->next;
            }

            int num_res = num1 + num2 + offset;
            offset = 0;
            if (num_res >= 10) {
                offset = 1;
                num_res -= 10;
            } 

            ListNode* new_node = new ListNode(num_res);
            res_prev->next = new_node;
            res_prev = new_node;

            if (l1 == nullptr && l2 == nullptr) {
                if (offset > 0) {
                    ListNode* new_node = new ListNode(offset);
                    res_prev->next = new_node;
                }

                break;
            } 
        }

        ListNode* res_head = res_dummy->next;
        delete res_dummy;
        return res_head;
    }
};
