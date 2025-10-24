class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        i = 0
        num = 0
        res = []
        while i < len(target):
            num += 1
            res.append("Push")
            if num == target[i]:
                i += 1
            else:
                res.append("Pop")

        return res
