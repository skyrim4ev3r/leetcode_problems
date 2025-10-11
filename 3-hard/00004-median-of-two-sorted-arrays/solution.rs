/*
	### Time Complexity Notice

        This solution has a time complexity of O(m + n), whereas the problem requires O(log (m + n)).
*/


impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let total_count = nums1.len() + nums2.len();
        let mut left_count = (total_count)/2;
        let right_count = left_count + 1;
        let mut left_val = 0;
        if left_count * 2 != total_count {
        	left_count += 1;
        }
        let mut count1=0usize;
        let mut count2=0usize;
        let mut last_nums1 = false;
        while count1 < nums1.len() || count2 < nums2.len() {
            if count1 < nums1.len() && count2 < nums2.len() {
                if(nums1[count1]< nums2[count2]) {
                    count1 += 1;
                    last_nums1 = true;
                } else {
                    count2 += 1;
                    last_nums1 = false;
                }
            }
            else if count1<nums1.len() {
                count1 += 1;
                last_nums1 = true;
            } else {
                count2 += 1;
                last_nums1 = false;
            }
            let current_count = count1 + count2;
            if current_count == left_count {
                if last_nums1 {
                    left_val = nums1[count1-1];
                } else {
                    left_val = nums2[count2-1];
                }
            }
            if current_count == right_count {
                if last_nums1 {
                    return (left_val + nums1[count1 - 1]) as f64 / 2.0f64;
                } else {
                    return (left_val + nums2[count2-1]) as f64 / 2.0f64;
                }
            }
         }
         0.0f64
    }
}
