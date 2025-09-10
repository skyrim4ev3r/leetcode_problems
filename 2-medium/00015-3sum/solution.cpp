class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int left{0}, right = nums.size() - 1, left_val, total_val, right_val;
        while (left + 1 < right && nums[left] <= 0 && nums[right] >= 0) {
            if ((nums[left]*-1) > nums[right]*2) {
                ++left;
                continue;
            }
            if ((nums[left]*-2) < nums[right]) {
                --right;
                continue;
            }
            left_val = nums[left];
            int k{right}, j{left+1};
            while (j < k) {
                total_val = nums[k] + nums[j] + left_val;
                if (val == 0) {
                    res.push_back(vector<int>{nums[left], nums[j], nums[k]});
                    right_val = nums[k];
                    while (nums[k] == right_val && k > j) {
                        --k;
                    }
                } else if (val > 0) {
                    --k;
                } else {
                    ++j;
                }
            }
            while (left < right && nums[left] == left_val) {
                ++left;
            }
        }
        return res;
    }
};
