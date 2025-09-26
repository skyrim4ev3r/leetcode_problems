class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i{2}; i < nums.size(); ++i) {
            int left = 0;
            int right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    sum += right - left;
                    right -= 1;
                } else {
                    left += 1;
                }
            }
        }

        return sum;
    }
};
