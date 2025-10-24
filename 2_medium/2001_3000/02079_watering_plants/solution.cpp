class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int can = capacity;
        int count = 0;
        for (int i{0}; i < plants.size(); ++i) {
            can -= plants[i];
            count += 1;
            if (i < plants.size() - 1 && can < plants[i + 1]) {
                count += 2 * (i + 1);
                can = capacity;
            }
        }

        return count;
    }
};
