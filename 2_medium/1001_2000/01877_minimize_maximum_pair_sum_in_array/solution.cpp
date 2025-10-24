class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums.size() - 1;
        int max_sum = 0; //maximum sum of minimized pairs

        while (l < r) {
            max_sum = max(max_sum, nums[r] + nums[l]);
            l += 1;
            r -= 1;
        }

        return max_sum;
    }
};
