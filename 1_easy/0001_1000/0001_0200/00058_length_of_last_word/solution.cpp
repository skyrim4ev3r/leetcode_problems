class Solution {
public:
    int lengthOfLastWord(string s) {

        int count = 0;
        bool is_counting_started = false;

        while (!s.empty()) {
            char ch = s.back();
            s.pop_back();
            if (ch != ' ') {
                is_counting_started = true;
            }

            if (is_counting_started) {
                if (ch != ' ') {
                    count += 1;
                } else {
                    break;
                }
            }
        }

        return count;
    }
};
