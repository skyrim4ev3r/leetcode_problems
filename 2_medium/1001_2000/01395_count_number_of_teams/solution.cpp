class Solution {
public:
    int numTeams(vector<int>& rating) {

        int count = 0;

	//using j for middle value
        for (int j{1}; j < rating.size() - 1; ++j) {

            int smaller_counts_left = 0;
            int bigger_counts_left = 0;
            for (int i{0}; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    ++smaller_counts_left;
                } else {
                    ++bigger_counts_left;
                }
            }

            int smaller_counts_right = 0;
            int bigger_counts_right = 0;
            for (int k{j+1}; k < rating.size(); ++k) {
                if (rating[k] < rating[j]) {
                    ++smaller_counts_right;
                } else {
                    ++bigger_counts_right;
                }
            }

            count += smaller_counts_left * bigger_counts_right + bigger_counts_left * smaller_counts_right;
        }

        return count;
    }
};
