class Solution {
public:
    int minFlips(string target) {
        char prev_ch = '0';
        int count = 0;
        for (auto ch: target) {
            if (ch != prev_ch) {
                prev_ch = ch;
                count += 1;
            }
        }

        return count;
    }
};
