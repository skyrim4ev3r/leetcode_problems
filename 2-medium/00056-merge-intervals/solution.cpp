class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });

        int index = 0;
        while (index != intervals.size()) {
            int right = index + 1;
            auto &tmp = intervals[index];
            while (right < intervals.size() && intervals[right][0] <= tmp[1]){
                tmp[1] = std::max(tmp[1], intervals[right][1]);
                ++right;
            }
            res.push_back(tmp);
            index = right;
        }

        return res;
    }
};
