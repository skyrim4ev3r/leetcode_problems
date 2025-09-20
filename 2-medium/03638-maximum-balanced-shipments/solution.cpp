class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int count = 0;
        int index = 0;
        
        while (index < weight.size() - 1) {
            if (weight[index] > weight[index + 1]) {
                count += 1;
                index += 2;
            } else {
                index += 1;
            }
        }

        return count;
    }
};
