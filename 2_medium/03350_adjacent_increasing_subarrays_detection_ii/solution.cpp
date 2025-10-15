class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {

        int max_adjacent_inc_len = 0;
        int max_single_inc_len = 0;
        int len = nums.size();
        int prev_inc_len = 0;
        int curr_inc_len = 1;

        for (int i = 1; i < len; ++i) {
            if (nums[i] > nums[i - 1]) {
                curr_inc_len += 1;
            } else {
                max_adjacent_inc_len = std::max(max_adjacent_inc_len, std::min(curr_inc_len, prev_inc_len));
                max_single_inc_len = std::max(max_single_inc_len, curr_inc_len);
                prev_inc_len = curr_inc_len;
                curr_inc_len = 1;
            }
        }

        max_adjacent_inc_len = std::max(max_adjacent_inc_len, std::min(curr_inc_len, prev_inc_len));
        max_single_inc_len = std::max(max_single_inc_len, curr_inc_len);

        return std::max(max_adjacent_inc_len, max_single_inc_len / 2);
    }
};
