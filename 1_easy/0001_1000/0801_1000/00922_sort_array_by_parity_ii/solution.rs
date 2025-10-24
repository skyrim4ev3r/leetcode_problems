impl Solution {
    pub fn sort_array_by_parity_ii(mut nums: Vec<i32>) -> Vec<i32> {

        let mut odd = 1_usize;
        let mut even = 0_usize;
        let len = nums.len();

        while even < len && odd < len {
            if (nums[odd] & 1) != 1 || (nums[even] & 1) != 0 {
                while (nums[odd] & 1) == 1 {
                    odd += 2;
                }
                while (nums[even] & 1) == 0 {
                    even += 2;
                }

                let tmp = nums[even];
                nums[even] = nums[odd];
                nums[odd] = tmp;

            }

            even += 2;
            odd += 2;
        }

        nums
    }
}
