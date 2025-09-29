impl Solution {
    fn backtrack(grid: &mut Vec<Vec<i32>>, i: usize, j: usize, count: &mut i32) {
        if grid[i][j] == 0 {
            return;
        }

        *count += 1;
        grid[i][j] = 0;

        if i > 0 {
            Self::backtrack(grid, i - 1, j, count);
        }
        if i < grid.len() - 1 {
            Self::backtrack(grid, i + 1, j, count);
        }

        if j > 0 {
            Self::backtrack(grid, i, j - 1, count);
        }
        if j < grid[0].len() - 1 {
            Self::backtrack(grid, i, j + 1, count);
        }
    }

    pub fn max_area_of_island(mut grid: Vec<Vec<i32>>) -> i32 {
        let mut max = 0;
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                if grid[i][j] == 1 {
                    let mut count = 0;
                    Self::backtrack(&mut grid, i, j, &mut count);
                    max = max.max(count);
                }
            }
        }

        max
    }
}
