class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long max{0}, sum{0}, left{0}, right{0};
        while (true) {
            while (left != nums.size() && nums[left] >= k) {
                ++left;
            }
            if (left == nums.size()) {
                break;
            }
            right = left;
            sum = nums[left];
            while (right >= left) {
                while (right <  nums.size() - 1 && (((sum + nums[right + 1]) * (right - left + 2)) < k)) {
                    ++right;
                    sum += nums[right];
                }
                if (right == nums.size() - 1 || nums[right+1] >= k) {
                    max += ((long long)(right - left + 1) * (right - left + 2))/2;
                    left = right + 1;
                    break;
                }
                max += right - left + 1;
                sum -= nums[left];
                ++left;
            }
        }
        return max;
    }
};
