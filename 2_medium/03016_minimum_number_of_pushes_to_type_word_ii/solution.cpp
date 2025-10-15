class Solution {
public:
    int minimumPushes(string word) {

        vector<int> freqs(26,0);

        for (auto ch: word) {
            freqs[ch - 'a'] += 1;
        }

        sort(freqs.rbegin(), freqs.rend());

        int total_cost = 0;

        for (int i{0}; i < freqs.size(); ++i) {
            int curr_cost = 1 + i / 8;
            total_cost += freqs[i] * curr_cost;
        }

        return total_cost;
    }
};
