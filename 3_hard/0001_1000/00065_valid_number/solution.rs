/*
    using flags for different cases, the name of flags are clear and does not need any more explanation
*/

impl Solution {
    pub fn is_number(s: String) -> bool {
        let (mut contains_e, mut contains_dot, mut contains_digits_before_e, mut contains_digits_after_e) = (false, false, false, false);
        //converting s into bytes
        let s = s.into_bytes();
        
        for i in 0..s.len() {
        
            if (s[i] >= b'A' && s[i] <= b'Z') || (s[i] >= b'a' && s[i] <= b'z') {
                if s[i] != b'e' as u8 && s[i] != b'E' {
                    return false;
                }
            }
            
            if s[i] == b'-' || s[i] == b'+' {
            
                if contains_e {
                
                    if s[i - 1] != b'e' && s[i - 1] != b'E' {
                        return false;
                    }
                    
                } else {
                
                    if i != 0 {
                        return false;
                    }
                    
                }
            }
            
            if s[i] == b'e' || s[i] == b'E' {
            
                if contains_e || !contains_digits_before_e {
                    return false;
                }
                
                contains_e = true;
            }
            
            if s[i] == b'.' {
            
                if(contains_e ||  contains_dot) {
                    return false;
                }
                
                contains_dot = true;
            }
            
            if s[i] >= b'0' && s[i] <= b'9' {
            
                if contains_e {
                    contains_digits_after_e = true;
                } else {
                    contains_digits_before_e = true;
                }
                
            }
        }
        
        if !contains_digits_before_e || (contains_e && !contains_digits_after_e) {
            return false;
        }
        
        true
    }
}
