class Solution {

    vector<vector<int>> res;

    void backtrack(vector<int> &candidates, vector<int> &curr_vec, int curr_pos, int target) {

        if (target == 0) {
            res.push_back(curr_vec);
            return;
        }

        int candidates_len{static_cast<int>(candidates.size())};

        if (curr_pos == candidates_len) {
            return;
        }

        for (int i{curr_pos}; i < candidates_len; ++i) {

            if (i != curr_pos && candidates[i] == candidates[i-1]) {
                continue;
            } 

            if (target - candidates[i] < 0) {
                break;
            }

            curr_vec.push_back(candidates[i]);
            backtrack(candidates, curr_vec, i + 1, target - candidates[i]);
            curr_vec.pop_back();           
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> curr_vec{};
        backtrack(candidates, curr_vec, 0, target);

        return res;
    }
};
