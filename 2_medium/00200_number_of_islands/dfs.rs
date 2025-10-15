impl Solution {
    fn dfs(grid: &mut Vec<Vec<char>>, directions: &[(i32, i32)], i: usize, j: usize) {

        if grid[i][j] == '0' {
            return;
        }

        grid[i][j] = '0';

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

            Self::dfs(grid, directions, new_i, new_j);
        }
    }
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {

        let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        let mut count = 0_i32;
        let rows = grid.len();
        let cols = grid[0].len();

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == '1' {
                    count += 1;
                    Self::dfs(&mut grid, &directions, i, j);
                }
            }
        }

        count
    }
}
