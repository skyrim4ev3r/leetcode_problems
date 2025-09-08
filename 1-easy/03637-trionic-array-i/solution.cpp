class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int count = nums[0] >= nums[1] ? 1000 : 0;
        for(int i{1}, count{}; i<nums.size() && count < 3; ++i)
            nums[i] == nums[i-1] ? count = 1000 : (count & 1) == (nums[i-1] < nums[i]) ? ++count : 1;
        return count == 2;
    }
};
