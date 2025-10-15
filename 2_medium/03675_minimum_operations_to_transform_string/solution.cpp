/*
    need to check string for smallest character
    which for this problem and in order are:

    b,c,d,..,z,a

    its like 'a' having ascii code of 'z' + 1 and the rest having thier ascii code

    and then return ==> NEW_SYSTEM_MAX_CHAR - founded_min_char
*/

class Solution {
        const char NEW_SYSTEM_MAX_CHAR = 'z' + 1;
public:
    int minOperations(string s) {
        char min_char = NEW_SYSTEM_MAX_CHAR;
        for (auto ch: s) {

            if (ch != 'a' && ch < min_char) {//ignoring 'a', default min_char is NEW_SYSTEM_MAX_CHAR 
                                            //              which is equal to 'a' ascii in new system 
                min_char = ch;
                if (min_char == 'b') {
                    break;
                }
            }
        }
        return NEW_SYSTEM_MAX_CHAR - min_char;
    }
};
