impl Solution {
    pub fn is_number(s: String) -> bool {
        let (mut contains_e, mut contains_dot, mut contains_digits_before_e, mut contains_digits_after_e) = (false, false, false, false);
        let s_as_bytes = s.as_bytes();
        for i in 0..s_as_bytes.len() {
            if (s_as_bytes[i] >= 'A' as u8 && s_as_bytes[i] <= 'Z' as u8) 
                || (s_as_bytes[i] >= 'a' as u8 && s_as_bytes[i] <= 'z' as u8)
            {
                if s_as_bytes[i] != 'e' as u8 && s_as_bytes[i] != 'E' as u8 {
                    return false;
                }
            }
            if s_as_bytes[i] == '-' as u8 || s_as_bytes[i] == '+' as u8 {
                if contains_e {
                    if s_as_bytes[i - 1] != 'e' as u8 && s_as_bytes[i - 1] != 'E' as u8 {
                        return false;
                    }
                } else {
                    if i != 0 {
                        return false;
                    }
                }
            }
            if s_as_bytes[i] == 'e' as u8 || s_as_bytes[i] == 'E' as u8 {
                if contains_e || !contains_digits_before_e {
                    return false;
                } 
                contains_e = true;
            }
            if s_as_bytes[i] == '.' as u8 {
                if(contains_e ||  contains_dot) {
                    return false;
                }
                contains_dot = true;
            }
            if s_as_bytes[i] >= '0' as u8 && s_as_bytes[i] <= '9' as u8 {
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
