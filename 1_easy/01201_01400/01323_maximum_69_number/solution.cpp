class Solution {
public:
    int maximum69Number (int num) {
        stack<int> digits{};

        while (num > 0) {
            digits.push(num % 10);
            num /= 10;
        }

        int res = 0;
        bool can_change = true;

        while (!digits.empty()) {
    
            res *= 10;

            int digit = digits.top();
            if (can_change && digit == 6) {
                can_change = false;
                res += 9;
            } else {
                res += digit;
            }

            digits.pop();
        }

        return res;
    }
};
