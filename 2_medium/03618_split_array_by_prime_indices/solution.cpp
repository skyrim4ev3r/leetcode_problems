class Solution {
    bool is_prime(int n) {
        if (n < 2) {
            return false;
        }

        if (n == 2 || n == 3 || n == 5) {
            return true;
        }

        if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) {
            return false;
        }

        for (int i{7}; i <= sqrt(n); i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
public:
    long long splitArray(vector<int>& nums) {
        long long sum = 0;
        for (int i{0}; i < nums.size(); ++i) {
            if (is_prime(i)) {
                sum += nums[i];
            } else {
                sum -= nums[i];
            }
        }

        return abs(sum);
    }
};
