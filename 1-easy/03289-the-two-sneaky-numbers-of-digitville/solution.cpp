class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        const int MAX_NUM = 100;
        int freqs[MAX_NUM]{};

        for (auto num: nums) {
            freqs[num] += 1;
        }

        vector<int> res{};
        for (int i{0}; i < MAX_NUM; ++i) {
            if (freqs[i] > 1) {
                res.push_back(i);
            }
        }

        return res;
    }
};
