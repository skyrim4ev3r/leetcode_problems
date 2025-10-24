class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i{1}; i < n; ++i) {
            int nums[] = {i, n-i};
            bool is_valid = true;
            for(auto a: nums) {
                if(! is_valid) {
                    break;
                }
                while(a > 0) {
                    if(a % 10 == 0) {
                        is_valid = false;
                        break;
                    }
                    a /= 10;
                }
            }
            if(is_valid){
                return vector<int>{i, n-i};
            }
        }
        return vector<int>{};
    }
};
