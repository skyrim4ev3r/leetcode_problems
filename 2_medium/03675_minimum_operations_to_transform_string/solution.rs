/*
    need to check string for smallest character
    which for this problem and in order are:

    b,c,d,..,z,a

    its like 'a' having ascii code of 'z' + 1 and the rest having thier ascii code

    and then return ==> NEW_SYSTEM_MAX_CHAR - founded_min_char
*/

impl Solution {
    pub fn min_operations(s: String) -> i32 {
        const NEW_SYSTEM_MAX_BYTE: u8 = b'z' + 1;
        let bytes = s.into_bytes();
        let mut min_byte = NEW_SYSTEM_MAX_BYTE;
        for byte in bytes {

            if byte != b'a' && byte < min_byte {//ignoring 'a', default min_char is NEW_SYSTEM_MAX_CHAR 
                                              //              which is equal to 'a' ascii in new system 
                
                min_byte = byte;
                if min_byte == b'b' {
                    break;
                }
            }
        }
        (NEW_SYSTEM_MAX_BYTE - min_byte) as i32
    }
}
