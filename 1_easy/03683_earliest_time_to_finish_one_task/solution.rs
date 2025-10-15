impl Solution {
    pub fn earliest_time(tasks: Vec<Vec<i32>>) -> i32 {
        let mut min = i32::MAX;
        tasks.into_iter().for_each(|task| min = min.min((task[0] + task[1])));        
        min
    }
}
