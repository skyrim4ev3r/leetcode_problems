class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int, int> counter_map{};
        int max_len = -1;
        for (auto &rec: rectangles) {
            int curr_len = min(rec[0], rec[1]);
            if (max_len <= curr_len) {
                max_len = curr_len;
                counter_map[max_len] += 1;
            }
        }

        return counter_map[max_len];
    }
};
