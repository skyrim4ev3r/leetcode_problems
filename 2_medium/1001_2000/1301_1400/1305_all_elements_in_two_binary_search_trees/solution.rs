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

    fn travers(node: &Option<Rc<RefCell<TreeNode>>>, vec: &mut Vec<i32>) {
        if let Some(n) = node {
            let borrowed_node = n.borrow();
            Self::travers(&borrowed_node.left, vec);
            vec.push(borrowed_node.val);
            Self::travers(&borrowed_node.right, vec);
        }
    }
    pub fn get_all_elements(root1: Option<Rc<RefCell<TreeNode>>>, root2: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut vec1: Vec<i32> = Vec::new();
        let mut vec2: Vec<i32> = Vec::new();
        Self::travers(&root1, &mut vec1);
        Self::travers(&root2, &mut vec2);
        let mut res: Vec<i32> = Vec::with_capacity(vec1.len() + vec2.len());
        
        let (mut i, mut j) = (0, 0);

        while i < vec1.len() && j < vec2.len() {
            if vec1[i] <= vec2[j] {
                res.push(vec1[i]);
                i += 1;
            } else {
                res.push(vec2[j]);
                j += 1;
            }
        }

        while i < vec1.len() {
            res.push(vec1[i]);
            i += 1;
        }
        while j < vec2.len() {
            res.push(vec2[j]);
            j += 1;
        }

        res
    }
}
