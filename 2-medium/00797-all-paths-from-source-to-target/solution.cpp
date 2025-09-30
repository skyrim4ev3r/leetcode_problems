class Solution {
    void backtrack(vector<vector<int>>& graph, int curr_index, vector<int> curr_vec, vector<vector<int>> &res) {

        curr_vec.push_back(curr_index);

        if (curr_index == graph.size() - 1 ){
            res.push_back(curr_vec);
        } else {
            for (auto g: graph[curr_index]) {
                backtrack(graph, g, curr_vec, res);
            }
        }

        curr_vec.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res{};

        backtrack(graph, 0, vector<int>(), res);

        return res;
    }
};
