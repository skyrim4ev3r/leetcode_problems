/*
    using two is_visited, one for atlantic ocean, one for pacific ocean

    dfs every cells that are reachable from """atlantic ocean"""
    dfs every cells that are reachable from """pacific ocean"""

    at final every cells in grid with is_visited = true in "both is_visited" are reachable from both side,
    and can add all of them to """result"""
*/

impl Solution {
    fn dfs(heights: &Vec<Vec<i32>>, is_visited: &mut Vec<Vec<bool>>, directions: &[(i32, i32)], i: usize, j:usize) {

        is_visited[i][j] = true;

        let rows_i32 = heights.len() as i32;
        let cols_i32 = heights[0].len() as i32;


        for &(x, y) in directions.iter() {
            let new_i_i32 = i as i32 + x;
            let new_j_i32 = j as i32 + y;

            if new_i_i32 >= rows_i32 || new_i_i32 < 0 || new_j_i32 >= cols_i32 || new_j_i32 < 0 {
                continue;
            }

            let new_i = new_i_i32 as usize;
            let new_j = new_j_i32 as usize;

            if is_visited[new_i][new_j] {
                continue;
            }

            if heights[new_i][new_j] < heights[i][j] {
                continue;
            }

            Self::dfs(heights, is_visited, directions, new_i, new_j)
        }
    }

    pub fn pacific_atlantic(heights: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let rows = heights.len();
        let cols = heights[0].len();

        let mut pacific_is_visited = vec![vec![false; cols]; rows];
        let mut atlantic_is_visited = vec![vec![false; cols]; rows];

        let directions: [(i32, i32); 4] = [(0, -1), (0, 1), (1, 0), (-1, 0)];


        for i in 0..rows {
            for j in 0..cols {
                if i == 0 || j == 0 {
                    Self::dfs(&heights, &mut pacific_is_visited, &directions, i, j);
                }

                if i == rows - 1 || j == cols - 1 {
                    Self::dfs(&heights, &mut atlantic_is_visited, &directions, i, j);
                }
            }
        }


        let mut res: Vec<Vec<i32>> = Vec::new();

        for i in 0..rows {
            for j in 0..cols {
                if atlantic_is_visited[i][j] && pacific_is_visited[i][j] {
                    res.push(vec![i as i32, j as i32]);
                }
            }
        }

        res
    }
}
