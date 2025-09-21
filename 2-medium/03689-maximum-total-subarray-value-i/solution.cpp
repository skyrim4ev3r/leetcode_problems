class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int max{INT_MIN}, min{INT_MAX};
        for (auto num: nums) {
            min = std::min(min, num);
            max = std::max(max, num);
        }
        return (long long)(max -min) * k;
    }
};
