class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double max = 0.0;
        for (int i{0}; i < points.size() -2; ++i) {
            for (int j{i + 1}; j < points.size() - 1; ++j) {
                for (int k{j + 1}; k < points.size(); ++k) {
                    // Calculate the area of the triangle using the determinant method
                    // Area = 0.5 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|
                    double area = abs(points[i][0] * ( points[j][1] - points[k][1])
                                + points[j][0] * ( points[k][1] - points[i][1])
                                + points[k][0] * ( points[i][1] - points[j][1])
                                )/(double) 2.0;

                    max = std::max(max, area);
                }
            }
        }

        return max;
    }
};
