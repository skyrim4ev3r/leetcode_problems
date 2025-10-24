class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max = -1;

        for (auto &sentence: sentences) {
            int count = 1;
            for (int i{0}; i < sentence.size(); ++i) {
                if (sentence[i] == ' ') {
                    count += 1;
                }
            }

            max = std::max(max, count);
        }

        return max;
    }
};
