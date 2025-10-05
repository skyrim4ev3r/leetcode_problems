class Solution {
public:
    vector<int> decimalRepresentation(int n) {

        long multiplier = 1;
        vector<int> res{};

        while (n > 0) {
            int tmp = (n % 10) * multiplier;

            if (tmp != 0) {
                res.push_back(tmp);
            }

            multiplier *= 10;
            n /= 10;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
