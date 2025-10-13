class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {

        vector<string> res{};
        string prev_word{};

        for (string &word: words) {
            string word_sorted = word;
            sort(word_sorted.begin(), word_sorted.end());
            if (prev_word != word_sorted) {
                res.push_back(word);
                prev_word = word_sorted;
            }
        }

        return res;
    }
};
