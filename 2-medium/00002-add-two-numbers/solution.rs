impl Solution {
    pub fn add_two_numbers(mut l1: Option<Box<ListNode>>, mut l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let (mut n1, mut n2, mut n3) : (Vec<i8>, Vec<i8>, Vec<i8>) = (Vec::new(), Vec::new(), Vec::new());
        let mut res: Option<Box<ListNode>> = None;
        while let Some(ptr) = l1 {
            n1.push(ptr.val as i8);
            l1 = ptr.next;
        }
        while let Some(ptr) = l2 {
            n2.push(ptr.val as i8);
            l2 = ptr.next;
        }
        let (mut i, mut j, mut ofs) = (0usize, 0usize, 0i8);
        loop {
            let mut tmp = n1[i] + n2[j] + ofs;
            ofs = 0;
            if(tmp > 9) {
                tmp -= 10;
                ofs = 1;
            }
            n3.push(tmp);
            if i==n1.len() -1 && j== n2.len() -1 {
                if(ofs > 0){
                    n3.push(ofs);
                }
                break;
            }
            if i < n1.len() -1 {
                i += 1;
            } else {
                n1[i] = 0;
            }
            if j < n2.len() -1 {
                j += 1;
            } else {
                n2[j] = 0;
            }
        }
        for num in n3.iter().rev() {
            res = Some(Box::new(ListNode { next : res, val: *num as i32}));
        }
        res
    }
}
