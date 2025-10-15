class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> freq_map{};
        for (auto ch: s) {
            freq_map[ch] += 1;
        }

        vector<int> freq{};
        freq.reserve(freq_map.size());
        for (const auto& pair : freq_map) {
            freq.push_back(pair.second);
        }

        sort(freq.rbegin(), freq.rend());

        int count = 0;
        for (int i{k}; i < freq.size(); ++i) {
            count += freq[i];
        }

        return count;
    }
};
