class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum{0}, max{INT_MIN}, nums_size{static_cast<int>(nums.size())};

        for(int i{0}; i != nums_size; ++i) {
            sum += nums[i];
            max = std::max(max, sum);
            
            // If sum be less than 0, then reset sum to 0 and start again
            sum = std::max(sum, 0);
        }

        return max;
    }
};
