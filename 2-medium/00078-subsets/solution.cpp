class Solution {
    vector<int> curr_vec{};
    vector<vector<int>> res{};
    void subset_recursive(vector<int>& nums, int start_index) {
        for (int i{start_index}; i < nums.size(); ++i) {
            curr_vec.push_back(nums[i]);
            res.push_back(curr_vec);
            subset_recursive(nums, i + 1);
            curr_vec.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back(vector<int>{});
        subset_recursive(nums, 0);

        return res;
    }
};
