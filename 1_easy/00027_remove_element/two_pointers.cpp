class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        size_t len = nums.size();
        size_t k = 0;

        for (size_t i{0}; i < len; ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k += 1;
            }
        }

        return k;
    }
};
