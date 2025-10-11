class Solution {
public:
    bool halvesAreAlike(string s) {

        int len = s.size();
        int half =  len / 2;
        int balance = 0;

        for (int i{0}; i < len; ++i) {
            switch (s[i]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    if (i < half) {
                        balance += 1;
                    } else {
                        balance -= 1;
                    }
                    break;
                default:
                    break;
            }
        }

        return balance == 0;
    }
};
