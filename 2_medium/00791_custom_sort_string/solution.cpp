/*
	O(m + n)	nested loop wont add complexity
*/

class Solution {
public:
    string customSortString(string order, string s) {

        const int freqs_len = 26;

        int freqs[freqs_len]{};
        string res{};

        for (char ch: s) {
            freqs[ch - 'a'] += 1;
        }

        for (char ch: order) {

            int freq_index = ch - 'a';
            int freq = freqs[freq_index];
            freqs[freq_index] = 0;

            for (int counter{0}; counter < freq; ++counter) {
                res.push_back(ch);
            }
        }

        for (int i{0}; i < freqs_len; ++i) {
            if (freqs[i] > 0) {
                char ch = i + 'a';
                for (int counter{0}; counter < freqs[i]; ++counter) {
                    res.push_back(ch);
                }
            }
        }

        return res;
    }
};
