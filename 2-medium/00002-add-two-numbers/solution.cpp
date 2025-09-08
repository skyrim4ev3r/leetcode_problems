class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<short> n1{}, n2{}, n3{};
        ListNode* res =nullptr;
        while(l1 != nullptr) {
            n1.push_back(static_cast<short>(l1->val));
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            n2.push_back(static_cast<short>(l2->val));
            l2 = l2->next;
        }
        short ofs{0};
        decltype(n1.size()) i{0}, j{0};
        while(true){
            short tmp = n1[i] + n2[j] + ofs;
            ofs = 0;
            if(tmp > 9) {
                tmp -= 10;
                ofs = 1;
            }
            n3.push_back(tmp);
            if(i==n1.size() -1 && j== n2.size() -1) {
                if(ofs > 0){
                    n3.push_back(ofs);
                }
                break;
            }
            if(i < n1.size() -1) {
                ++i;
            } else {
                n1[i] = 0;
            }
            if(j < n2.size() -1) {
                ++j;
            } else {
                n2[j] = 0;
            }
        }
        for(auto it{n3.rbegin()}; it != n3.rend(); ++it) {
            auto tmp = new ListNode();
            tmp->next = res;
            res=tmp;
            res->val = static_cast<int>(*it);
        }
        return res;
    }
};
