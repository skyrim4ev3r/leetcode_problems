class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int nums_len = nums.size();
        int index = 0;

        for (int i{1}; i < nums_len; ++i) {
            if(nums[i] != nums[i - 1]) {
                index += 1;
                nums[index] = nums[i];
            }
        }

        return index + 1;
    }
};
