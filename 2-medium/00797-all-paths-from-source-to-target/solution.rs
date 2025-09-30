impl Solution {
    fn backtrack(graph: &Vec<Vec<i32>>, curr_index: usize, curr_vec: &mut Vec<i32>, res: &mut Vec<Vec<i32>>) {        

        curr_vec.push(curr_index as i32);

        if curr_index == graph.len() - 1 {
            res.push(curr_vec.clone());
        } else {
            for &g in graph[curr_index].iter() {
                Self::backtrack(graph, g as usize, curr_vec, res);
            }
        }

        curr_vec.pop();
    }
    pub fn all_paths_source_target(graph: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        
        Self::backtrack(&graph, 0, &mut Vec::<i32>::new(), &mut res);

        res
    }
}
