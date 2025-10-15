class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        unordered_set<int> nums_set{};
        vector<int> res{};
        int common = 0;
        for (int i{0}; i < a.size(); ++i) {
            if (nums_set.contains(a[i])) {
                nums_set.erase(a[i]);
                common += 1;
            } else {
                nums_set.insert(a[i]);
            }

            if (nums_set.contains(b[i])) {
                nums_set.erase(b[i]);
                common += 1;
            } else {
                nums_set.insert(b[i]);
            }

            res.push_back(common);
        }

        return res;
    }
};
