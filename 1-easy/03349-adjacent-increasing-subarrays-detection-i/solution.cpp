class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        int left = 0;
        int right = (2 * k) - 1;
        int len = nums.size();

        while (right < len) {
            bool is_increasing = true;

            for (int i{left + 1}; i <= right; ++i) {
                if (i == left + k) {
                    continue;
                }

                if (nums[i - 1] >= nums[i]) {
                    is_increasing = false;
                    break;
                }
            }

            if (is_increasing) {
                return true;
            }

            left += 1;
            right += 1;
        }

        return false;
    }
};
