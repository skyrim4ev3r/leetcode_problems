class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (l == nums.size() || nums[l] != target) {
            return vector<int>{-1, -1};
        }

        int r = std::upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        return vector<int>{l, r};
    }
};
