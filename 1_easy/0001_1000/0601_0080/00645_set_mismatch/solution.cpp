class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int duplicate_num = -1;
        int missing_num = -1;
        int len = nums.size();

        for (int i{0}; i < len; ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                duplicate_num = abs(nums[i]);
            } else {
                nums[index] *= -1;
            }
        }

         for (int i{0}; i < len; ++i) {
            if (nums[i] > 0) {
                missing_num = i + 1;
                break;
            } 
        }

        return vector<int>{duplicate_num, missing_num};
    }
};
