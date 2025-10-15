class Solution {
public:
    string addBinary(string a, string b) {
        char offset = 0;

        if (a.size() < b.size()) {
            std::swap(a, b);
        }

        int a_bytes_len = a.size();

        for (int i{a_bytes_len - 1}; i >= 0; --i) {

            char b_char = '0';

            if (!b.empty()) {
                b_char = b.back();
                b.pop_back();
            }

            char byte_sum = (a[i] - '0') + (b_char - '0') + offset;
            offset = 0;
            if (byte_sum > 1) {
                byte_sum -= 2;
                offset = 1;
            }

            a[i] = byte_sum + '0';

            if (offset == 0 && b.empty()) {
                break;
            }
        }

        if (offset == 1) {
            a.insert(a.begin(), '1');
        }

        return a;
    }
};
