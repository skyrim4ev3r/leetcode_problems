class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        int n = mat.size();
        int sum = 0;

        for (int i{0}; i < n; ++i) {
            sum += mat[i][i];
            sum += mat[n - 1 -i][i];
        }

        if ((n & 1) == 1) {
            int center = n / 2;
            sum -= mat[center][center];
        }

        return sum;
    }
};
