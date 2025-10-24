class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i = 0;
        int num = 0;
        vector<string> res{};
        while (i < target.size()) {
            num += 1;
            res.push_back("Push");
            if (num == target[i]) {
                i += 1;
            } else {
                res.push_back("Pop");
            }
        }

        return res;
    }
};
