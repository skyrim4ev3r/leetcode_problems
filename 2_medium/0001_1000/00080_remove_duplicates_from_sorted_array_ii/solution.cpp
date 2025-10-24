class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nums_len = nums.size();

        if (nums_len < 3) {
            return nums_len;
        }

        int curr_len = 2;

        for (int i{2}; i < nums_len; ++i) {
            if (nums[i] == nums[curr_len - 2]) {
                continue;
            }

            nums[curr_len] = nums[i];
            curr_len += 1;
        }

        return curr_len;
    }
};
