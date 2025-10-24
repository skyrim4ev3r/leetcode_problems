class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) {
            return 0; // No range to consider
        }

        sort(nums.begin(), nums.end());
        int left = 0;
        int right = k - 1;
        int min_difference = INT_MAX; // Initialize to maximum possible value

        while (right < nums.size()) {
            min_difference = min(min_difference, nums[right] - nums[left]);
            ++left;
            ++right;
        }

        return min_difference;
    }
};
