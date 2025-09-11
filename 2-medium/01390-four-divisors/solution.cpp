class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for(auto num: nums) {
        
            int sq = sqrt(num);
            
            // if this condition be true then number of divisors are odd and cant be 4
            if(sq*sq == num) { 
                continue;
            }
            
            // 1 and num are two divisors of num
            // so we start from count=2 and sum =1+num
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
