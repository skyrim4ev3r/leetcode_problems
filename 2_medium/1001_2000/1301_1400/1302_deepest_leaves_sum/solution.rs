// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn backtrack_deepest_leaves_sum(curr_node_opt: Option<Rc<RefCell<TreeNode>>>, curr_level: i32, max_level: &mut i32, sum: &mut i32) {
        if let Some(curr_node) = curr_node_opt {
            if (curr_level > *max_level) {
                *max_level = curr_level;
                *sum = curr_node.borrow().val;
            } else if (curr_level == *max_level) {
                *sum += curr_node.borrow().val;
            }

            Self::backtrack_deepest_leaves_sum(curr_node.borrow().left.clone(), curr_level + 1, max_level, sum);
            Self::backtrack_deepest_leaves_sum(curr_node.borrow().right.clone(), curr_level + 1, max_level, sum);
        }
    }
    pub fn deepest_leaves_sum(mut root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut sum = 0;
        Self::backtrack_deepest_leaves_sum(root,0, &mut -1, &mut sum);

        sum
    }
}
