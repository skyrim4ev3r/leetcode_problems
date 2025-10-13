use std::collections::VecDeque;

impl Solution {
    pub fn shortest_path_binary_matrix(grid: Vec<Vec<i32>>) -> i32 {

        if grid[0][0] == 1 {
            return -1;
        }

        let mut rows = grid.len();
        let mut cols = grid[0].len();
        let mut steps = vec![vec![i32::MAX; cols]; rows];
        let mut deque = VecDeque::new();
        let directions = [(1, -1), (1, 0), (1, 1), (0, 1), (0, -1), (-1, -1), (-1, 0), (-1, 1)];

        steps[0][0] = 1;
        deque.push_back((0, 0));

        while let Some((i, j)) = deque.pop_front() {
            let old_step = steps[i][j];
            for &(x, y) in directions.iter() {
                let new_i_i32 = i as i32 + x;
                let new_j_i32 = j as i32 + y;

                if new_i_i32 < 0 || new_j_i32 < 0 {
                    continue;
                }
                
                let new_i = new_i_i32 as usize;
                let new_j = new_j_i32 as usize;

                if new_i >= rows || new_j >= cols {
                    continue;
                }

                if grid[new_i][new_j] == 1 || steps[new_i][new_j] <= old_step + 1 {
                    continue;
                }

                steps[new_i][new_j] = old_step + 1;

                deque.push_back((new_i, new_j));
            }
        }

        if steps[rows - 1][cols - 1] == i32::MAX {
            return -1;
        }

        steps[rows - 1][cols - 1]
    } 
}
