impl Solution {
    pub fn reverse_submatrix(mut grid: Vec<Vec<i32>>, x: i32, y: i32, k: i32) -> Vec<Vec<i32>> {
        (0..k).clone().for_each(|j| (0..k/2).clone().for_each(|i| (grid[(x+i) as usize][(y+j)  as usize], grid[(x+k-i-1) as usize][(y+j) as usize]) = (grid[(x+k-i-1) as usize][(y+j) as usize],grid[(x+i) as usize][(y+j)  as usize])));                
        grid
    }
}