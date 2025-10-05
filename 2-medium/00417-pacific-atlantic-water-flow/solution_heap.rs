/*
    using two min_heap, one for atlantic ocean, one for pacific ocean
    using two is_visited, one for atlantic ocean, one for pacific ocean

    using a grid with defalut valu of 0 and size of m*n

    incremnet every cells in grid that are reachable from """atlantic ocean""" by """1"""
    incremnet every cells in grid that are reachable from """pacific ocean""" by """1"""

    at final every cells in grid with value of """2""" are reachable from both side, and we can add all of them to """result"""
*/

use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Debug, Eq, PartialEq)]
struct Cell {
    height: i32,
    i: usize,
    j: usize,
}

// Imp ordering for min_heap
impl Ord for Cell {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other.height.cmp(&self.height)
    }
}

impl PartialOrd for Cell {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl Solution {

    #[inline]
    fn solve(heights: &Vec<Vec<i32>>, grid: &mut Vec<Vec<i32>>, heap: &mut BinaryHeap<Cell>, is_visited: &mut Vec<Vec<bool>>) {
        let rows_i32 = heights.len() as i32;
        let cols_i32 = heights[0].len() as i32;

        let directions = [[0, -1], [0, 1], [1, 0], [-1, 0_i32]];

         while let Some(cell) = heap.pop() {
            for direction in directions.iter() {
                let new_i_i32 = cell.i as i32 + direction[0];
                let new_j_i32 = cell.j as i32 + direction[1];

                if new_i_i32 >= rows_i32 || new_i_i32 < 0 || new_j_i32 >= cols_i32 || new_j_i32 < 0 {
                    continue;
                }

                let new_i = new_i_i32 as usize;
                let new_j = new_j_i32 as usize;
        
                if is_visited[new_i][new_j] {
                    continue;
                }

                is_visited[new_i][new_j] = true;

                let new_height = heights[new_i][new_j];
    
                if new_height < cell.height {
                    continue;
                }

                grid[new_i][new_j] += 1;
                heap.push(Cell {height: new_height, i: new_i, j: new_j});
            }

        }
    }

    pub fn pacific_atlantic(heights: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let rows = heights.len();
        let cols = heights[0].len();

        let mut atlantic_heap: BinaryHeap<Cell> = BinaryHeap::new();
        let mut pacific_heap: BinaryHeap<Cell> = BinaryHeap::new();


        let mut grid = vec![vec![0_i32; cols]; rows];
        let mut atlantic_is_visited = vec![vec![false; cols]; rows];
        let mut pacific_is_visited = vec![vec![false; cols]; rows];


        for i in 0..rows {
            for j in 0..cols {
                if i == 0 || j == 0 {
                    pacific_heap.push(Cell {height: heights[i][j], i, j});
                    pacific_is_visited[i][j] = true;
                    grid[i][j] += 1;
                }

                if i == rows - 1 || j == cols - 1 {
                    atlantic_heap.push(Cell {height: heights[i][j], i, j});
                    atlantic_is_visited[i][j] = true;
                    grid[i][j] += 1;
                }
            }
        }

        Self::solve(&heights, &mut grid, &mut atlantic_heap, &mut atlantic_is_visited);
        Self::solve(&heights, &mut grid, &mut pacific_heap, &mut pacific_is_visited);

        let mut res: Vec<Vec<i32>> = Vec::new();

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 2 {
                    res.push(vec![i as i32, j as i32]);
                }
            }
        }
       
        res
    }
}
