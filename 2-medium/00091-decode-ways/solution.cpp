class Solution {
    vector<int> mem;
    int count;
    int solve(string &s, int pos) {
        if (pos == s.size()){
            return 1;
        }

        if (mem[pos] > -1) {
            return mem[pos];
        }

        if(s[pos] == '0') {
            mem[pos] = 0;
            return 0;
        }

        int res = solve(s, pos + 1);
        if(pos < s.size() -1 && (s[pos] == '1' || (s[pos] == '2' && s[pos+1] < '7'))) {
            res += solve(s, pos + 2);
        }

        mem[pos] = res;
        return res;
    }
public:
    int numDecodings(string s) {
        mem = vector<int>(s.size(), -1);
        return solve(s, 0);
    }
};
