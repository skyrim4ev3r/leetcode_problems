class Solution {
public:
    string getHint(string secret, string guess) {
        //wg stands for "wrong guess"
        int wg_digit_counts_secret[10]{};
        int wg_digit_counts_guess[10]{};

        int correct_guess_count = 0;
        int correct_digit_wrong_pos_count = 0;

        for (auto i{0}; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                correct_guess_count += 1;
            } else {
                wg_digit_counts_secret[secret[i] - '0'] += 1;
                wg_digit_counts_guess[guess[i] - '0'] += 1;
            }
        }

        for (auto i{0}; i < 10; ++i) {
            correct_digit_wrong_pos_count += min(wg_digit_counts_guess[i],(wg_digit_counts_secret[i]));
        }

        return  to_string(correct_guess_count) + "A" + to_string(correct_digit_wrong_pos_count) + "B";
    }
};
