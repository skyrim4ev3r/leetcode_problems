impl Solution {
    pub fn add_two_numbers(mut l1: Option<Box<ListNode>>, mut l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut res_dummy: Option<Box<ListNode>> = Some(Box::new(ListNode::new(0)));
        let mut res_prev = &mut res_dummy;
        let mut offset = 0;
        loop {
            let mut num1 = 0_i32;
            if l1.is_some() {
                let mut l1_node = l1.unwrap();
                num1 = l1_node.val;
                l1 = l1_node.next.take();
            }

            let mut num2 = 0_i32;
            if l2.is_some() {
                let mut l2_node = l2.unwrap();
                num2 = l2_node.val;
                l2 = l2_node.next.take();
            }

            let mut res_num = num1 + num2 + offset;
            offset = 0;
            if res_num >= 10 {
                offset = 1;
                res_num -= 10;
            }

            let mut new_node: Option<Box<ListNode>> = Some(Box::new(ListNode::new(res_num)));
            res_prev.as_mut().unwrap().next = new_node;
            res_prev = &mut res_prev.as_mut().unwrap().next;

            if l1.is_none() && l2.is_none() {
                if offset > 0 {
                    let mut new_node: Option<Box<ListNode>> = Some(Box::new(ListNode::new(offset)));
                    res_prev.as_mut().unwrap().next = new_node;
                }

                break;
            }
        }
        
        res_dummy.unwrap().next.take()
    }
}
