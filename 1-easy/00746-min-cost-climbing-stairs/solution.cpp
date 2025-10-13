class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();

        for (int i{len - 3}; i >= 0; --i) {
            cost[i] += std::min(cost[i + 1], cost[i + 2]);
        }

        return std::min(cost[0], cost[1]);
    }
};
