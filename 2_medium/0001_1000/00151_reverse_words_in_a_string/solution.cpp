class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string word;
        string s_rev{};

        while (ss >> word) {
            if (!s_rev.empty()) {
                s_rev.push_back(' ');
            }
            s_rev.append(word.rbegin(), word.rend());
        }

        reverse(s_rev.begin(), s_rev.end());

        return s_rev;
    }
};
