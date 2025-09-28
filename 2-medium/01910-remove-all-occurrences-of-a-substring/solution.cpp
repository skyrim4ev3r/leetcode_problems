class Solution {
     bool remove_occurrences_helper(string &s, string &part) {
        int left = 0;
        int right = part.size() - 1;

        while (right < s.size()) {
            bool is_equal = true;
            for (int i{0}; i < part.size(); ++i) {
                if (s[left + i] != part[i]) {
                    is_equal = false;
                    break;
                }
            }
            if (is_equal) {
                string res = s.substr(0, left);
                res += s.substr(right + 1);
                s = res;
                return true;
            }
            right += 1;
            left += 1;
        }

        return false;
    }

public:
    string removeOccurrences(string s, string part) {
        while (remove_occurrences_helper(s, part)) {}
        return s;
    }
};
