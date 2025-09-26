class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {

        vector<int> res(heights.size(), 0);
        stack<int> stack{};

        for (int i{(int)heights.size() - 1}; i >= 0; --i) {
            while (!stack.empty()) {

                res[i] += 1;

                int val = stack.top();
                if (val <= heights[i]) {
                    stack.pop();
                } else {
                    break;
                }

            }

            stack.push(heights[i]);
        }

        return res;
    }
};
