class Solution {
public:
    string convertToBase7(int num) {
        string res{""};
        bool is_negative = false;
        if(num==0) {
            return "0";
        }
        if(num<0) {
            is_negative = true;
            num*=-1;
        }
        while(num>0) {
            res = char(num % 7 + '0') + res;
            num/=7;
        }
        if(is_negative) {
            res = '-' + res;
        }
        return res;
    }
};
