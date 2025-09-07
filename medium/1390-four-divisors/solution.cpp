class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for(auto num: nums) {
            int sq = sqrt(num);
            if(sq*sq == num) {
                continue;
            }
            int count = 2;
            int sum = 1 + num;
            for(int i{2}; i <= sq; ++i){
                if(num % i == 0) {
                    sum += i + num / i;
                    count += 2;
                    if(count > 4) {
                        break;
                    }
                }
            }
            if(count == 4) {
                res += sum;
            }
        }
        return res;
    }
};
