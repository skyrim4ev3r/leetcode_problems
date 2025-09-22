class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        for (int i{0}; i < nums.size(); ++i) {
            for (int ans{nums[i] / 2}; ans < nums[i]; ++ans) {
                if ((ans | (ans + 1)) == nums[i]) {
                    res[i] = ans;
                    break;
                }
            }
        }

        return res;
    }
};
