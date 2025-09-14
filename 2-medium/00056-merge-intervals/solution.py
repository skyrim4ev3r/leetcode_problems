class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        intervals.sort(key=lambda x: x[0])

        index = 0
        res = []

        while index != len(intervals):
            tmp_list = intervals[index][:]
            right = index + 1
            while right != len(intervals) and intervals[right][0] <= tmp_list[1]:
                tmp_list[1] = max(tmp_list[1], intervals[right][1])
                right += 1
            res.append(tmp_list)
            index = right

        return res        
