class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        std::unordered_map<int, int> res;
        for(auto num : nums){
            if(res.find(num) != res.end())
                ++res[num];
            else
                res[num] = 1;
        }
        for(const auto& pair : res) 
            if(pair.second > 1)
            {
                bool is_prime = true;
                for(int i{2}; i<=sqrt(pair.second);++i)
                {
                    if(pair.second % i == 0)
                    {
                        is_prime = false;
                        break;
                    }
                }
                if(is_prime)
                    return true;
            }
        return false;
    }
};
