class Solution {
public:
    int countPairs(vector<int>& nums, int k) {

        int nums_len = nums.size();
        int count = 0;

        for (int i{0}; i < nums_len; ++i) {
            for (int j{i + 1}; j < nums_len; ++j) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
