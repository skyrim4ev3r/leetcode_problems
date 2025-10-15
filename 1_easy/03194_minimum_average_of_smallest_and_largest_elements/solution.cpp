class Solution {
public:
    double minimumAverage(vector<int>& nums) {

        int l = 0;
        int r = nums.size() - 1;
        double avg_min = (double) INT_MAX;

        sort(nums.begin(), nums.end());

        while (l < r) {
            avg_min = min(avg_min, ((double) (nums[l] + nums[r])) / 2);
            --r;
            ++l;
        }

        return avg_min;
    }
};
