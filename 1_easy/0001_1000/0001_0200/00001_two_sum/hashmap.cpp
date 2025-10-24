class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        size_t len = nums.size();
        unordered_map <int, int> m{};
        vector<int> res{};

        for (size_t i{0}; i < len; ++i) {

            auto it = m.find(target-nums[i]);

            if (it != nullptr) {
                res.push_back(static_cast<int>(i));
                res.push_back(it->second);
                return res;
            }

            m[nums[i]] = static_cast<int>(i);
        }

        return res;
    }
};
