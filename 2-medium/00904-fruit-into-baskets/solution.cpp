class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fruit_count;
        int left = 0;
        int max = 0;

        for (int right{0}; right < fruits.size(); ++right) {

            ++fruit_count[fruits[right]];
            while (fruit_count.size() > 2) {

                fruit_count[fruits[left]] -= 1;

                if (fruit_count[fruits[left]] == 0) {
                    fruit_count.erase(fruits[left]);
                }

                ++left;
            }

            max = std::max(max, right - left + 1);
        }

        return max;
    }
};
