class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int nums_len = nums.size();
        for (int i{0}; i < nums_len; ++i) {
            nums[i] *= nums[i];
        }

        int left = 0;
        int right = nums_len - 1;
        vector<int> res(nums_len, 0);
        int res_index = nums_len;

        while (left <= right) {
            res_index -= 1;
            if (nums[left] < nums[right]) {
                res[res_index] = nums[right];
                right -= 1;
            } else {
                res[res_index] = nums[left];
                left += 1;
            }
        }

        return  res;
    }
};
