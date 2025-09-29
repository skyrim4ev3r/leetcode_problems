class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max = INT_MIN;
        for (auto num: nums) {
            max = std::max(max, num);
        }

        return max * k + (k * (k - 1)) / 2;
    }
};
