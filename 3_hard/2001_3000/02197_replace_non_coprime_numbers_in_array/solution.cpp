class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {

        vector<int> res;

        for (int index{0}; index < nums.size(); ++index) {

            int tmp = nums[index];
            while (res.size() != 0 && gcd(tmp, res[res.size() - 1]) > 1) {
                tmp =  lcm(tmp, res[res.size() - 1]);
                res.pop_back();
            }
            res.push_back(tmp);
        }

        return res;
    }
};
