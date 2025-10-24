class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (index == nums.size() || nums[index] != target) {
            return -1;
        }
        return index;
    }
};
