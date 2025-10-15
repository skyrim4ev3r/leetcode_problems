class Solution {
public:
    string decodeMessage(string key, string message) {
        char key_map[26]{};

        char curr_char = 'a';
        for (char ch: key) {

            int index = (ch - 'a');

            if (ch != ' ' && key_map[index] == 0) {
                key_map[index] = curr_char;
                curr_char += 1;
            }
        }

        string res{};

        for (char ch: message) {
            if (ch == ' ') {
                res.push_back(ch);
            } else {
                res.push_back(key_map[(ch - 'a')]);
            }
        }

        return res;
    }
};
