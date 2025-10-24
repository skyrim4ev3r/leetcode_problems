class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {

        int len = coordinates.size();
        int first_dy = coordinates[1][1] - coordinates[0][1];
        int first_dx = coordinates[1][0] - coordinates[0][0];

        for (int i{2}; i < len; ++i) {
            int curr_dy = coordinates[i][1] - coordinates[0][1];
            int curr_dx = coordinates[i][0] - coordinates[0][0];

            if (first_dy * curr_dx != first_dx * curr_dy) {
                return false;
            }
        }

        return true;
    }
};
