class Solution {
    int max_or = 0;
    int count = 0;
    void subsets_backtrack(vector<int> &nums, int curr_or, int start_index) {
        if (curr_or == max_or) {
            count += std::pow(2, (nums.size() - start_index));
            return;
        }
        for (int i{start_index}; i < nums.size(); ++i) {
            subsets_backtrack(nums, curr_or | nums[i], i + 1);
        }
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        max_or = 0;
        count = 0;
        for (auto num: nums) {
            max_or |= num;
        }
        subsets_backtrack(nums, 0, 0);

        return count;
    }
};
