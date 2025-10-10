class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i{0}; i < n; ++i) {
            if (nums[i] <= 0) {
                nums[i] = INT_MAX;
            }
        }

        for (int i{0}; i < n; ++i) {
            int num = abs(nums[i]) - 1;
            if (num < n) {
                if (nums[num] > 0) {
                    nums[num] *= -1;
                }
            }
        }

        for (int i{0}; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
