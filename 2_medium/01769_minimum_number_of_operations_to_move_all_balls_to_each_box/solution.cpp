class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.size(), 0);
    
        for (int i{0}, sum{0}, balls{0}; i < boxes.size(); ++i) {
            sum += balls;
            res[i] += sum;

            if (boxes[i] == '1') {
                balls += 1;
            }
        }

        for (int i{(int) boxes.size() - 1}, sum{0}, balls{0}; i >= 0; --i) {
            sum += balls;
            res[i] += sum;

            if (boxes[i] == '1') {
                balls += 1;
            }
        }

        return res;
    }
};
