class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        counter_map = {}
        max_len = -1
        for rec in rectangles:
            curr_len = min(rec[0], rec[1])
            if max_len < curr_len:
                max_len = curr_len
                counter_map[curr_len] = 1
            elif max_len == curr_len:
                counter_map[curr_len] += 1

        return counter_map[max_len]
