class Solution {
public:
    vector<string> stringSequence(string target) {
        string screen = "";
        vector<string> res {};
        int index = 0;
        while (screen != target) {
            if (screen.size() == 0 || screen[index] == target[index]) {
                screen.push_back('a');
                index = screen.size() - 1;
            } else {
                screen[index] += 1;
            }

            res.push_back(screen);
        }

        return res;
    }
};
