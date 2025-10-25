class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res = 0;
        for (auto num: nums) {
            res |= num;
        }

        return res;
    }
};
