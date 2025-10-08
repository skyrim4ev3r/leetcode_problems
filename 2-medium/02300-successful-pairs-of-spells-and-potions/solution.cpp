class Solution {
    int lower_bound(vector<int>& arr, int target) {
        auto it = std::lower_bound(arr.begin(), arr.end(), target);
        return it - arr.begin();
    }

public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int potionsLen = potions.size();
        vector<int> res;

        for (int spell : spells) {
            long long minSuccessNum = (success + spell - 1) / spell; // Its ceiling of success / spell

            if (minSuccessNum > INT32_MAX) {
                res.push_back(0);
            } else {
                int index = lower_bound(potions, static_cast<int>(minSuccessNum));
                res.push_back(potionsLen - index);
            }
        }

        return res;
    }
};
