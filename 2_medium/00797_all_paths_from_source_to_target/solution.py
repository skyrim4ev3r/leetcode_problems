class Solution:
    def backtrack(self, graph, curr_index, curr_vec, res):

        curr_vec.append(curr_index)

        if curr_index == len(graph) - 1:
            res.append(curr_vec[:])
        else:
            for g in graph[curr_index]:
                self.backtrack(graph, g, curr_vec, res)

        curr_vec.pop()

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        res = []

        self.backtrack(graph, 0, [], res)

        return res
