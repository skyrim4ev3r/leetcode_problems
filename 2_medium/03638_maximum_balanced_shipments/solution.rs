impl Solution {
    pub fn max_balanced_shipments(weight: Vec<i32>) -> i32 {

        let mut count = 0;
        let mut index = 0;
        
        while index < weight.len() - 1 {
            if weight[index] > weight[index + 1] {
                count += 1;
                index += 2;
            } else {
                index += 1;
            }
        }

        count
    }
}
