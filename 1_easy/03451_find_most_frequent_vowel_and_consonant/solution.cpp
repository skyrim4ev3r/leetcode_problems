class Solution {
public:
    int maxFreqSum(string s) {

        const int ALPHABET_LEN = 26;
        int frequencies[ALPHABET_LEN] = {0};
        for (auto ch: s) {
            ++frequencies[ch - 'a'];
        }

        int max_frequency_vowels = 0;
        int max_frequency_consonants = 0;
        for (int i{0}; i < ALPHABET_LEN; ++i) {

            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20){// 'a', 'e', 'i', 'o', 'u'
                max_frequency_vowels = std::max(max_frequency_vowels, frequencies[i]);
            } else {
                max_frequency_consonants = std::max(max_frequency_consonants, frequencies[i]);
            }
        }

        return max_frequency_consonants + max_frequency_vowels;
    }
};
