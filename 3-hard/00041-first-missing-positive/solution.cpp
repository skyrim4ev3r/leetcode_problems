class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // at worst case if vector of len n contains 1..n then we need n+1 space
        // that extra space is pos[0] and it will get ignore to easily map valid nums to thier index
        vector<bool> pos(n + 1, false);
        for (auto num: nums) {
            // we can ignore numers greather than n, because if ther be any then at least some int between 1..n is missed
            if (num > 0 && num <= n) {
                pos[num] = true;
            }
        }
        // start from 1, ignoring pos[0]
        for (int i{1}; i <= n; ++i) {
            if (pos[i] == false) {
                return i;
            }
        }
        return n + 1;//this happens at worst case when vector of len n have 1..n values
    }
};
