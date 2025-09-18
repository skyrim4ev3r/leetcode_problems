impl Solution {
    fn is_valid_coupon(coupon: &[u8]) -> bool {
        !coupon.is_empty() && coupon.iter().all(|&ch| {
            (ch >= b'a' && ch <= b'z') || 
            (ch >= b'A' && ch <= b'Z') || 
            (ch >= b'0' && ch <= b'9') || 
            ch == b'_'
        })
    }

    pub fn validate_coupons(code: Vec<String>, business_line: Vec<String>, is_active: Vec<bool>) -> Vec<String> {
        let valid_categories: [&str; 4] = ["electronics", "grocery", "pharmacy", "restaurant"];
        let mut res: Vec<(String, usize)> = Vec::new();

        for i in 0..is_active.len() {
            if !is_active[i] {
                continue;
            }
            if let Some(index) = valid_categories.iter().position(|&x| x == business_line[i]) {
                if !Self::is_valid_coupon(code[i].as_bytes()) {
                    continue;
                }
                res.push((code[i].clone(), index));
            }
        }

        res.sort_by(|a, b| {
            let cmp = a.1.cmp(&b.1);
            if cmp == std::cmp::Ordering::Equal {
                a.0.cmp(&b.0)
            } else {
                cmp
            }
        });

        res.into_iter().map(|(first, _)| first).collect()
    }
}

