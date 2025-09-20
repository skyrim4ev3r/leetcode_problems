impl Solution {

    fn backtrack_with_vec(grid: &mut [Vec<i32>], i: usize, j: usize) -> i32 {
        let rows = grid.len();
        let cols = grid[i].len();
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


    fn backtrack_with_recursion(grid: &mut [Vec<i32>], i: usize, j: usize) -> i32 {

        if grid[i][j] == 0 {
            return 0;
        }

        let mut sum = grid[i][j];
        grid[i][j] = 0;

        if i > 0 {
            sum += Self::backtrack_with_recursion(grid, i - 1, j);
        }
        if i < grid.len() - 1 {
            sum += Self::backtrack_with_recursion(grid, i + 1, j);
        }

        if j > 0 {
            sum += Self::backtrack_with_recursion(grid, i, j - 1);
        }
        if j < grid[i].len() - 1 {
            sum+= Self::backtrack_with_recursion(grid, i, j + 1);
        }

        sum
    }

    pub fn count_islands(mut grid: Vec<Vec<i32>>, k: i32) -> i32 {

        let mut count = 0;

        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                if grid[i][j] != 0 {                    
                    //let mut sum = Self::backtrack_with_recursion(&mut grid, i, j);

                    let mut sum = Self::backtrack_with_vec(&mut grid, i, j);
                    if sum % k == 0 {
                        count += 1;
                    }
                }
            }
        }

        count
    }
}
