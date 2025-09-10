impl Solution {
    fn update_valid_positions(s: String, valid_positions: &mut Vec<bool>) {
        let mut stack: Vec<(usize, u8)> = Vec::new();
        let str_as_bytes = s.as_bytes();
        for i in 0..str_as_bytes.len() {
            if let Some(top_element) = stack.last() {
                if (str_as_bytes[i] == '}' as u8 && top_element.1 == '{' as u8)
                    || (str_as_bytes[i] == ']' as u8 && top_element.1 == '[' as u8)
                    || (str_as_bytes[i] == ')' as u8 && top_element.1 == '(' as u8)
                {
                    valid_positions[top_element.0] = true; 
                    valid_positions[i] = true;
                    stack.pop();
                    continue;
                }
            }
            stack.push((i, str_as_bytes[i]));
        }
    }
    fn max_continuous_substr_of_true(valid_positions: Vec<bool>) -> i32 {
        let (mut max, mut curr) = (0, 0);
        for pos in valid_positions {
            if (pos) {
                curr += 1;
            } else {
                curr = 0;
            } 
            if (curr > max) {
                max = curr;
            }
        }
        max
    }
    pub fn longest_valid_parentheses(s: String) -> i32 {  
        let mut valid_positions = vec![false; s.as_bytes().len()];      
        Self::update_valid_positions(s, &mut valid_positions);        
        Self::max_continuous_substr_of_true(valid_positions)
    }
}
