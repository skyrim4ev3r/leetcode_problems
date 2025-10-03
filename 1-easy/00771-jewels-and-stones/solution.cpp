class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        bool jewels_map[128]{false};
        for (char jewel: jewels) {
            jewels_map[jewel] = true;
        }

        int count = 0;

        for (char stone: stones) {
            if (jewels_map[stone]) {
                count += 1;
            }
        }

        return count;
    }
};
