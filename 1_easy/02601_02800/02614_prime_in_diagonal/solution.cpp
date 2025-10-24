class Solution {
    bool is_prime(int num) {
        if (num <= 1) {
            return false;
        }

        if (num == 2 || num == 3 || num == 5) {
            return true;
        }

        if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0) {
            return false;
        }

        int sq = sqrt(num);
        for (int i{7}; i <= sq; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int max = 0;
        for(int i{0}; i < n; ++i) {
            if (max < nums[i][i] && is_prime(nums[i][i])) {
                max = nums[i][i];
            }
            if (max < nums[i][n - 1 - i] && is_prime(nums[i][n - 1 - i])) {
                max = nums[i][n - 1 - i];
            }
        }

        return max;
    }
};
