// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_two_lists(mut list1: Option<Box<ListNode>>, mut list2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Some(Box::new(ListNode::new(0)));
        let mut prev = &mut dummy;

        while list1.is_some() && list2.is_some() {
            let prev_node = prev.as_mut().unwrap();
            if list1.as_mut().unwrap().val < list2.as_mut().unwrap().val {
                prev_node.next = list1;
                prev = &mut prev_node.next;
                list1 = prev.as_mut().unwrap().next.take();
            } else {
                prev_node.next = list2;
                prev = &mut prev_node.next;
                list2 = prev.as_mut().unwrap().next.take();
            }
        }

        prev.as_mut().unwrap().next = list1.or(list2);

        dummy.unwrap().next
    }
}
