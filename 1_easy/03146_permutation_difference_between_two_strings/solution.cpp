class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int len = s.size();
        int position_diff[26]{};

        for (int i{0}; i < len; ++i) {
            position_diff[s[i] - 'a'] -= i;
            position_diff[t[i] - 'a'] += i;
        }

        int sum = 0;
        for (int i{0}; i < 26; ++i) {
            sum += abs(position_diff[i]);
        }

        return sum;
    }
};
