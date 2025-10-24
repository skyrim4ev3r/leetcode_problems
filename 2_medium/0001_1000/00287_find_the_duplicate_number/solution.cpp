class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int num{0};
        for (int i{0}; i <= nums.size(); ++i) {
            num = abs(nums[i]);
            if (nums[num] > 0) {
                nums[num] *= -1;
            } else {
                break;
            }
        }

        for (int i{0}; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                nums[i] *= -1;
            }
        }
        return num;
    }
};
