class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {

        int odd = 1;
        int even = 0;
        int len = nums.size();

        while (even < len && odd < len) {
            if ((nums[odd] & 1) != 1 || (nums[even] & 1) != 0) {
                while ((nums[odd] & 1) == 1) {
                    odd += 2;
                }
                while ((nums[even] & 1) == 0) {
                    even += 2;
                }

                int tmp = nums[even];
                nums[even] = nums[odd];
                nums[odd] = tmp;

            }

            even += 2;
            odd += 2;
        }

        return nums;
    }
};
