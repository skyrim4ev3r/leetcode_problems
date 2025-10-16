class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        size_t value_usize = static_cast<size_t>(value);
        vector<int> remainders(value_usize, 0);

        for (int num: nums) {
            size_t index = static_cast<size_t>(abs(num)) % value_usize;

                // Adjust index for negative numbers
            if (index != 0 && num < 0) {
                index = value_usize - index;
            }

            remainders[index] += 1;
        }

        int res = 0;
        while (true) {
            size_t index = static_cast<size_t>(res) % value_usize;

            if (remainders[index] == 0) {
                break;
            }

            remainders[index] -= 1;

            res += 1;
        }

        return res;
    }
};
