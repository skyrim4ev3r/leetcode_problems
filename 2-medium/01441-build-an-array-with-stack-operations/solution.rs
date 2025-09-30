impl Solution {
    pub fn build_array(target: Vec<i32>, n: i32) -> Vec<String> {
        let mut i = 0;
        let mut num = 0;
        let mut res: Vec<String> = Vec::new(); 
        while i < target.len() {
            num += 1;
            res.push("Push".to_string());
            if num == target[i] {
                i += 1;
            } else {
                res.push("Pop".to_string());
            }
        }
    
        res
    }
}
