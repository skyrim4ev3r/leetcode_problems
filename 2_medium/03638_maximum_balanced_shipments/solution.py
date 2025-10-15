class Solution:
    def maxBalancedShipments(self, weight: List[int]) -> int:
        count = 0
        index = 0

        while index < len(weight) - 1:
            if weight[index] > weight[index + 1]:
                count += 1
                index += 2
            else:
                index += 1

        return count
