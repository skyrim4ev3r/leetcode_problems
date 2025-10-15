class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> res(nums.size(), 0);

        int sum = 0;
        for (int i{0}; i < nums.size(); ++i)  {
            res[i] += sum;
            sum += nums[i];
        }

        sum = 0;
        for (int i{(int) nums.size() - 1}; i >= 0; --i)  {
            res[i] = abs(res[i] - sum);
            sum += nums[i];
        }

        return res;
    }
};
