class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int count = 0;

        for (auto num1: nums1) {
            for (auto num2: nums2) {
                if (num1 % (k * num2) == 0) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
