class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> map;

        for (int num: nums) {
            map[num] += 1;
        }

        for (auto pair: map) {
            if (pair.second == 1) {
                sum += pair.first;
            }
        }

        return sum;
    }
};
