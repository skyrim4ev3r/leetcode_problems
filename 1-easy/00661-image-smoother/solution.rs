impl Solution {
    pub fn image_smoother(img: Vec<Vec<i32>>) -> Vec<Vec<i32>> {

        let rows = img.len();
        let cols = img[0].len();

        let mut res: Vec<Vec<i32>> = vec![vec![0_i32; cols]; rows];
        let directions = [(0, -1), (0, 1), (1, -1), (1, 0), (1, 1),  (-1, -1),(-1, 0),(-1, 1)];

        for i in 0..rows {
            for j in 0..cols {
                let mut sum = img[i][j];
                let mut count = 1_i32;

                for &(x, y) in directions.iter() {
                    let new_i_i32 = i as i32 + x;
                    let new_j_i32 = j as i32 + y;

                    if new_i_i32 < 0 || new_j_i32 < 0 {
                        continue;
                    }

                    let new_i = new_i_i32 as usize;
                    let new_j = new_j_i32 as usize;

                    if new_i >= rows || new_j >= cols {
                        continue;
                    }

                    count += 1;
                    sum += img[new_i][new_j];
                }
                
                res[i][j] = sum / count;
            }
        }

        res
    }
}
