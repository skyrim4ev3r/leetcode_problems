class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0;
        long long total_sum = 0;
        int left = 0;
        int right = 0;
        int nums_len = nums.size();

        while(true) {
            while (left < nums_len && nums[left] >= k) {
                left += 1;
            }

            if (left >= nums_len) {
                break;
            }

            right = left;
            total_sum = 0;

            while (left <= right) {
                while (right <  nums_len && ((total_sum + nums[right]) * (right - left + 1)) < k) {
                    total_sum += nums[right];
                    right += 1;
                }

                if (right == nums_len || nums[right] >= k) {
                    count += ((long long)(right - left) * (right - left + 1)) / 2;
                    left = right;
                    break;
                }

                count += (right - left);
                total_sum -= nums[left];
                left += 1;
            }
        }

        return count;
    }
};
