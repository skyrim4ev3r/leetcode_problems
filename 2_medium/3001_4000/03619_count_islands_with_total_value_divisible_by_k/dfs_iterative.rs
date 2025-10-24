impl Solution {

    fn dfs_iterative(grid: &mut [Vec<i32>], i: usize, j: usize, rows: usize, cols: usize) -> i32 {

        let mut sum = grid[i][j];

        grid[i][j] = 0;

        let mut stack = vec![(i, j)];

        while let Some((x, y)) = stack.pop() {

            if x > 0 && grid[x - 1][y] != 0 {
                sum += grid[x - 1][y];
                grid[x - 1][y] = 0;
                stack.push((x - 1, y));
            }

            if x < rows - 1 && grid[x + 1][y] != 0 {
                sum += grid[x + 1][y];
                grid[x + 1][y] = 0;
                stack.push((x + 1, y));
            }

            if y > 0 && grid[x][y - 1] != 0 {
                sum += grid[x][y - 1];
                grid[x][y - 1] = 0;
                stack.push((x, y - 1));
            }

            if y < cols - 1 && grid[x][y + 1] != 0 {
                sum += grid[x][y + 1];
                grid[x][y + 1] = 0;
                stack.push((x, y + 1));
            }
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

                    let sum = Self::dfs_iterative(&mut grid, i, j, rows, cols);

                    if sum % k == 0 {
                        count += 1;
                    }
                }
            }
        }

        count
    }
}