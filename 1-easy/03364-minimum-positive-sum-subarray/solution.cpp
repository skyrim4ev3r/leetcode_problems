class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int min_positive_sum = -1, n = nums.size();
        l -= 1;
        r -= 1;

        for (int i{0}; i < n - l; ++i) {
            int sum = 0;
            for (int j{i}; j <= min(i + r, n -1); ++j) {
                sum += nums[j];
                if (j >= i + l && sum > 0 && (sum < min_positive_sum || min_positive_sum == -1)) {
                    min_positive_sum = sum;
                }
            }
        }

        return min_positive_sum;
    }
};
