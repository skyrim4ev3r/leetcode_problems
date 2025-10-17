class Solution {

    // This iterative approach using a stack is generally slower than the recursive function.
    // In LeetCode test cases, the recursive method often performs better.
    // What factors contribute to this performance difference? 
    // Is it the overhead of managing the stack or the use of std::pair?
    long backtrack_with_stack(vector<vector<int>> &grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[i].size();
        long sum = grid[i][j];

        grid[i][j] = 0;

        stack<pair<int, int>> stack;
        stack.push(pair(i, j));

        while (!stack.empty()) {
            auto tmp = stack.top();
            int x = tmp.first;
            int y = tmp.second;
            stack.pop();

            if (x > 0 && grid[x - 1][y] != 0) {
                sum += grid[x - 1][y];
                grid[x - 1][y] = 0;
                stack.push(pair(x - 1, y));
            }

            if (x < rows - 1 && grid[x + 1][y] != 0) {
                sum += grid[x + 1][y];
                grid[x + 1][y] = 0;
                stack.push(pair(x + 1, y));
            }

            if (y > 0 && grid[x][y - 1] != 0) {
                sum += grid[x][y - 1];
                grid[x][y - 1] = 0;
                stack.push(pair(x, y - 1));
            }

            if (y < cols - 1 && grid[x][y + 1] != 0) {
                sum += grid[x][y + 1];
                grid[x][y + 1] = 0;
                stack.push(pair(x, y + 1));
            }
        }

        return sum;
    }

    // This recursive approach is generally faster than the stack-based approach in LeetCode test cases.
    // But why does this method perform better in the context of LeetCode's test cases?
    // Maybe the lower overhead of function calls and simpler control flow contribute to its efficiency?
    long backtrack_with_recursion(vector<vector<int>> &grid, int i, int j) {

        if (grid[i][j] == 0) {
            return 0;
        }

        long sum = grid[i][j];
        grid[i][j] = 0;

        if (i > 0) {
            sum += backtrack_with_recursion(grid, i - 1, j);
        }
        if (i < grid.size() - 1) {
            sum += backtrack_with_recursion(grid, i + 1, j);
        }

        if (j > 0) {
            sum += backtrack_with_recursion(grid, i, j - 1);
        }
        if (j < grid[i].size() - 1) {
            sum += backtrack_with_recursion(grid, i, j + 1);
        }

        return sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;

        for (int i{0}; i < grid.size(); ++i) {
            for (int j{0}; j < grid[i].size(); ++j) {
                if (grid[i][j] != 0) {
                    long sum = backtrack_with_recursion(grid, i, j);

                    // Comment the prev line && Uncomment the line below to test the stack-based approach.

                    //long sum = backtrack_with_stack(grid, i, j);
                    if (sum % k == 0) {
                        count += 1;
                    }
                }
            }
        }

        return count;
    }
};
