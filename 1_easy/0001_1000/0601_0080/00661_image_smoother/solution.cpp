class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int rows = img.size();
        int cols = img[0].size();

        vector<vector<int>> res = vector<vector<int>>(rows, vector<int>(cols, 0));
        vector<vector<int>> directions{{0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}, {-1, -1}, {-1, 0}, {-1, 1}};

        for (int i{0}; i < rows; ++i) {
            for (int j{0}; j < cols; ++j) {
                int sum = img[i][j];
                int count = 1;

                for (auto &dir: directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (new_i < 0 || new_j < 0 || new_i >= rows || new_j >= cols) {
                        continue;
                    }

                    count += 1;
                    sum += img[new_i][new_j];
                }

                res[i][j] = sum / count;
            }
        }

        return res;
    }
};
