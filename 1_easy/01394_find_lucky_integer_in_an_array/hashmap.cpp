class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> map{};

        for (int &num: arr) {
            map[num] += 1;
        }

        int max_lucky{-1};
        for (auto &it: map) {
            if (it.first == it.second) {
                max_lucky = max(max_lucky, it.first);
            }
        }

        return max_lucky;
    }
};
