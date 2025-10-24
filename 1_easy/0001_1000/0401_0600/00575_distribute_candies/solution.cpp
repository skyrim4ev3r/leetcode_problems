class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> candy_set;
        for (int candy: candyType) {
            candy_set.insert(candy);
        }

        return std::min(candyType.size() / 2, candy_set.size());
    }
};
