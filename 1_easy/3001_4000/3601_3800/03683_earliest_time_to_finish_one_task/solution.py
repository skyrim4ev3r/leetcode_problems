class Solution:
    def earliestTime(self, tasks: List[List[int]]) -> int:
        INT_MAX = 1_000_000_000_000
        min_val = INT_MAX
        for task in tasks:
            min_val = min(min_val, task[0] + task[1])
        return min_val
