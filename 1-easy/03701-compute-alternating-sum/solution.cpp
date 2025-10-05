class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum {0};
        int nums_len{static_cast<int>(nums.size())};

        for (int i{0}; i < nums_len; ++i) {
            if ((i & 1) == 0) {
                sum += nums[i];
            } else {
                sum -= nums[i];
            }
        }

        return sum;
    }
};
