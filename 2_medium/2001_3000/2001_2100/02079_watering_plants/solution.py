class Solution:
    def wateringPlants(self, plants: List[int], capacity: int) -> int:
        can = capacity
        count = 0
        for i in range(len(plants)):
            can -= plants[i]
            count += 1
            if i < len(plants) - 1 and can < plants[i + 1]:
                count += 2 * (i + 1)
                can = capacity

        return count
