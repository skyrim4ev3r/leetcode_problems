impl Solution {
    pub fn minimum_area(grid: Vec<Vec<i32>>) -> i32 {
        let mut max_i = 0;
        let mut min_i = grid.len();
        let mut max_j = 0;
        let mut min_j = grid[0].len();

        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                if grid[i][j] == 1 {
                    max_i = i; // Directly assign since var "i" is always growing
                    if i < min_i {
                        min_i = i;
                    }
                    max_j = max_j.max(j);
                    min_j = min_j.min(j);
                }
            }
        }
        
        if max_i < min_i {
            return 0;
        }

        ((max_i - min_i + 1) * (max_j - min_j + 1)) as i32
    }
}
