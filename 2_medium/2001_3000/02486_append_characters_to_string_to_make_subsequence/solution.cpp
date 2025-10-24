class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();

        int s_index = 0;
        int t_index = 0;

        while (s_index < s_len && t_index < t_len) {
            if (s[s_index] == t[t_index]) {
                t_index += 1;
            }
            s_index += 1;
        }

        return t_len - t_index;
    }
};
