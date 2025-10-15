class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groups_map{};
        vector<vector<int>> res{};

        for (int i{0}; i <  groupSizes.size(); ++i) {
            const int g_size = groupSizes[i];
            groups_map[g_size].push_back(i);

            if (groups_map[g_size].size() == g_size) {
                res.push_back(move(groups_map[g_size]));
            }
        }

        return res;
    }
};
