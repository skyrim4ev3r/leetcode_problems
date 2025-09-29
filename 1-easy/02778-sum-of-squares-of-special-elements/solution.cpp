class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int sqrt_len = sqrt(n);
        for (int i{1}; i <= sqrt_len; ++i) {
            if (n % i == 0) {
                int other_index = n / i;
                res += std::pow(nums[i - 1], 2);
                if (other_index != i) {
                    res += std::pow(nums[other_index - 1], 2);
                }
            }
        }

        return res;
    }
};
