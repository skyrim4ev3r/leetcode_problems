class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count{0};
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(decltype(s.size()) i{0}, j{0}; i<s.size() && j < g.size(); ++i) { 
            if(g[j] <= s[i]) {
                ++count;
                ++j;
            }
        }
        return count;
    }
};
