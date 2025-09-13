class Solution {
    vector<vector<int>> res;
    void solve(vector<int> &candidates, vector<int> &curr_vec, int curr_pos, int target) {

        if (target == 0) {
            res.push_back(curr_vec);
            return;
        }

        if (curr_pos == candidates.size()) {
            return;
        }

        for(int i{curr_pos}; i < candidates.size(); ++i) {

            if (i != curr_pos && candidates[i] == candidates[i-1]) {
                continue;
            } else if (target - candidates[i] >= 0) {
                curr_vec.push_back(candidates[i]);
                solve(candidates, curr_vec, i + 1, target - candidates[i]);
                curr_vec.pop_back();
            } else {
                break;
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> curr_vec{};
        solve(candidates, curr_vec, 0, target);

        return res;
    }
};
