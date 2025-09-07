class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> m;
        vector<int> res;
        for(int i{0};i<nums.size();++i)
        {
            auto it=m.find(target-nums[i]);
            if(it!=nullptr)
            {
                res.push_back(i);
                res.push_back(it->second);
                return res;
            }
            m[nums[i]]=i;
        }
        return res;
    }
};
