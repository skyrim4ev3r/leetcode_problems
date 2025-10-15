class Solution:
    def heightChecker(self, heights: List[int]) -> int:

        heights_clone = heights[:]
        count = 0
        heights_len = len(heights)

        heights_clone.sort()

        for i in range(heights_len):
            if heights[i] != heights_clone[i]:
                count += 1

        return count
