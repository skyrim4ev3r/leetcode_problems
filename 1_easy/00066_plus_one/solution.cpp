class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int offset = 1;
        int digits_len = digits.size();

        for (int i = digits_len - 1; i >= 0; --i) {
            digits[i] += offset;
            offset = 0;
            if (digits[i] > 9) {
                digits[i] -= 10;
                offset = 1;
            } else {
                break;
            }
        }

        if (offset == 1) {
            digits.push_back(0);
            digits[0] = 1;
        }

        return digits;
    }
};
