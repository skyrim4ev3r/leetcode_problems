class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {

        int even_count = 0;
        for (auto num: nums) {
            if ((num & 1) == 0) {
                even_count += 1;
            }
        }

        for (int i{0}; i < nums.size(); ++i) {
            if (i < even_count) {
                nums[i] = 0;
            } else {
                nums[i] = 1;
            }
        }

        return nums;
    }
};
