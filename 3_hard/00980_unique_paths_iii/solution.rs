impl Solution {
    fn dfs(grid: &mut Vec<Vec<i32>>, directions: &[(i32, i32)],
                count: &mut i32, target_path_len: i32, curr_path_len: i32, i: usize, j:usize) 
    {
        if grid[i][j] == -1 {
            return;
        }
    
        if grid[i][j] == 2 {
            if target_path_len == curr_path_len {
                *count += 1;
            }

            return;
        }

        grid[i][j] = -1;
        for &(x, y) in directions.iter() {

            let new_i_i32 = i as i32 + x;
            let new_j_i32 = j as i32 + y;

            if new_i_i32 < 0 || new_j_i32 < 0 {
                continue;
            }
    
            let new_i = new_i_i32 as usize;
            let new_j = new_j_i32 as usize;

            if new_i >= grid.len() || new_j >= grid[0].len() {
                continue;
            }

            Self::dfs(grid, directions, count, target_path_len, curr_path_len + 1, new_i, new_j);
        }
        grid[i][j] = 0;
    }
    pub fn unique_paths_iii(mut grid: Vec<Vec<i32>>) -> i32 {
        let mut target_path_len = 0;

        let rows = grid.len();
        let cols = grid[0].len();
        let mut start = (0_usize, 0_usize);
        let directions = [(-1, 0), (1, 0), (0, -1), (0, 1)];

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 0 || grid[i][j] == 2 {
                    target_path_len += 1;
                }

                if grid[i][j] == 1 {
                    start.0 = i;
                    start.1 = j;
                }
            }
        }

        let mut count = 0_i32;
        Self::dfs(&mut grid, &directions, &mut count, target_path_len, 0, start.0, start.1);

        count
    }
}
