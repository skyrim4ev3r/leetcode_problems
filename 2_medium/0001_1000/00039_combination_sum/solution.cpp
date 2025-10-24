class Solution {
    vector<vector<int>> res;
    vector<int> tmp;

    void backtrack(vector<int>& candidates, int candidates_len, int target, int curr) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }

        for (int i = curr; i < candidates_len; ++i) {
            if (target - candidates[i] >= 0) {
                tmp.push_back(candidates[i]);
                backtrack(candidates, candidates_len, target - candidates[i], i);
                tmp.pop_back();
            } else {
                break;
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, candidates.size(), target, 0);

        return res;
    }
};
