class Solution {
    inline bool is_vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    string mask_vowels(string &s) {
        string tmp{s};
        for (int i{0}; i < s.size(); ++i) {
            if (is_vowel(s[i])) {
                tmp[i] = '*';
            }
        }
        return tmp;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map <string, string*> lower_map{}, lower_vowel_map{};
        unordered_set<string> exact_set{};
         for (int i{0}; i < wordlist.size(); ++i) {

            auto word_lower{wordlist[i]};
            std::transform(word_lower.begin(), word_lower.end(), word_lower.begin(), [](unsigned char ch) { return std::tolower(ch); });
            auto word_lower_maskvowel = mask_vowels(word_lower);

            lower_map.emplace(word_lower, &wordlist[i]);
            lower_vowel_map.emplace(word_lower_maskvowel, &wordlist[i]);

            exact_set.insert(wordlist[i]);
        }

        for (int i{0}; i < queries.size(); ++i) {

            if (exact_set.find(queries[i]) == exact_set.end()) {

                auto query_lower{queries[i]};
                std::transform(query_lower.begin(), query_lower.end(), query_lower.begin(), [](unsigned char ch) { return std::tolower(ch); });
                if (lower_map.find(query_lower) != lower_map.end()) {
                    queries[i] = *lower_map[query_lower];
                } else {

                    auto query_lower_vowel{mask_vowels(query_lower)};
                    if (lower_vowel_map.find(query_lower_vowel) != lower_vowel_map.end()) {
                        queries[i] = *lower_vowel_map[query_lower_vowel];
                    } else {
                        queries[i] = "";
                    }

                }

            }
        }
        return queries;
    }
};
