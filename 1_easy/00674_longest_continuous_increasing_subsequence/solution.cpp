class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max = 1;
        int curr = 1;
        int len = nums.size();

        for (int i{1}; i < len; ++i) {
            if (nums[i] > nums[i - 1]) {
                curr += 1;
                max = std::max(max, curr);
            } else {
                curr = 1;
            }
        }

        return max;
    }
};
