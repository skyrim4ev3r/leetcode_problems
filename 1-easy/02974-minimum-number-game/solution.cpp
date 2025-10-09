class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int len = nums.size();

        sort(nums.begin(), nums.end());

        for (int i{0}; i < len - 1; i+=2) {
            int tmp = nums[i + 1];
            nums[i + 1] = nums[i];
            nums[i] = tmp;
        }

        return nums;
    }
};
