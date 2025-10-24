class Solution {
public:
    char findTheDifference(string s, string t) {
        char added_char{0};

        for (char &ch: s) {
            added_char ^= ch;
        }

        for (char &ch: t) {
            added_char ^= ch;
        }

        return added_char;
    }
};
