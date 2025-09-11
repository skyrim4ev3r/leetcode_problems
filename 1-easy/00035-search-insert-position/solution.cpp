class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int right{static_cast<int>(nums.size()-1)}, left{0};
        while (left <= right) {
            int mid = (right + left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
