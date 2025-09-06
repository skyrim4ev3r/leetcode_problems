class Solution {
public:
    bool checkDivisibility(int n) {
        int x{n}, d_sum{0}, d_mul{1};
        while (x > 0) {
            int tmp = x % 10;
            d_sum += tmp;
            d_mul *= tmp;
            x /= 10;
        }
        return n % (d_sum + d_mul) == 0;
    }
};
