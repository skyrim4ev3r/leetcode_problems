class Solution {
public:
    int heightChecker(vector<int>& h1) {

        vector<int> h2 = h1;
        int count = 0;
        size_t len = h1.size();

        sort(h2.begin(), h2.end());

        for (size_t i{0}; i < len; ++i) {
            if (h1[i] != h2[i]) {
                count += 1;
            }
        }

        return count;
    }
};
