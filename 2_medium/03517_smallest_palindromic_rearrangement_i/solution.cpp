class Solution {
public:
    string smallestPalindrome(string s) {
        const int SIZE = 26;
        int freq[SIZE]{};

        for (auto ch: s) {
            freq[ch - 'a'] += 1;
        }

        int l{0}, r{(int)s.size() - 1};

        for (int i{0}; i < SIZE; ++i) {

            if ((freq[i] & 1) == 1) {
                int mid = s.size() / 2;
                s[mid] = i + 'a';
            }

            for (int j{0}; j < freq[i]/2; ++j) {
                s[l] = i + 'a';
                s[r] = i + 'a';
                l += 1;
                r -= 1;
            }
        }

        return s;
    }
};
