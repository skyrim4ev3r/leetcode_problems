class Solution:
    def stableMountains(self, height: List[int], threshold: int) -> List[int]:
        res = []
        for i in range(len(height) - 1):
            if height[i] > threshold:
                res.append(i + 1)

        return res
