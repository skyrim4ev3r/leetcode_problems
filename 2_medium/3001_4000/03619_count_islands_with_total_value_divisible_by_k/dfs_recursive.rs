impl Solution {
    fn dfs_recursive(grid: &mut [Vec<i32>], i: usize, j: usize, rows: usize, cols: usize) -> i32 {

        if grid[i][j] == 0 {
            return 0;
        }

        let mut sum = grid[i][j];
        grid[i][j] = 0;

        if i > 0 {
            sum += Self::dfs_recursive(grid, i - 1, j, rows, cols);
        }
        if i < rows - 1 {
            sum += Self::dfs_recursive(grid, i + 1, j, rows, cols);
        }

        if j > 0 {
            sum += Self::dfs_recursive(grid, i, j - 1, rows, cols);
        }
        if j < cols - 1 {
            sum += Self::dfs_recursive(grid, i, j + 1, rows, cols);
        }

        sum
    }

    pub fn count_islands(mut grid: Vec<Vec<i32>>, k: i32) -> i32 {

        let mut count = 0;
        let rows = grid.len();
        let cols = grid[0].len();

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] != 0 {

                    let mut sum = Self::dfs_recursive(&mut grid, i, j, rows, cols);

                    if sum % k == 0 {
                        count += 1;
                    }
                }
            }
        }

        count
    }
}
