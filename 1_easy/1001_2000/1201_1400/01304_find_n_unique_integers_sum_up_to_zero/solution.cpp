class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res {};
        for(int i{1}; i < 1 + n/2; ++i) {
            res.push_back(i);
            res.push_back(-1 * i);
        }
        if(n % 2 == 1) {
            res.push_back(0);
        }
        return res;
    }
};
