class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
        int count_zeros = 0;

        for (int num: arr) {
            if (num == 0) {
                count_zeros += 1;
            }
        }

        int new_index = len - 1 + count_zeros;
        for (int i{len - 1}; i >= 0; --i) {
            if (new_index < len) {
                arr[new_index] = arr[i];
            }

            if (arr[i] == 0) {
                new_index -= 1;
                if (new_index < len) {
                    arr[new_index] = 0;
                }
            }

            new_index -= 1;
        }
    }
};
