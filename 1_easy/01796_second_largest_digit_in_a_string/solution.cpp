class Solution {
public:
    int secondHighest(string s) {

        int is_seen[10]{};

        for (char ch: s) {
            if (ch >= '0' && ch <= '9') {
                is_seen[ch - '0'] = true;
            }
        }

        int count = 0;

        for (int i{9}; i >= 0; --i) {
            if (is_seen[i]) {
                count += 1;
                if (count == 2) {
                    return i;
                }
            }
        }

        return -1;
    }
};
