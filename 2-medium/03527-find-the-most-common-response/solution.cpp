class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> words_count;
        for (auto response: responses) {
            unordered_set<string> unique;
            for (auto word: response) {
                if (unique.insert(word).second) {
                    words_count[word] += 1;
                }
            }
        }

        int curr_max_count = 0;
        string curr_str{};
        for (auto pair: words_count) {
            if (pair.second > curr_max_count) {
                curr_max_count = pair.second;
                curr_str = pair.first;
            } else if (pair.second == curr_max_count && pair.first < curr_str) {
                curr_str = pair.first;
            }
        }

        return curr_str;
    }
};
