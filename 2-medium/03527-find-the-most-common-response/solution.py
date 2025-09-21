class Solution:
    def findCommonResponse(self, responses: List[List[str]]) -> str:

        words_count = {}
        for response in responses:
            response_set = set(response)
            for word in response_set:
                if word in words_count:
                    words_count[word] += 1
                else:
                    words_count[word] = 1

        curr_max_count = 0
        curr_str = ""
        for word, count in words_count.items():
            if count > curr_max_count:
                curr_max_count = count
                curr_str = word
            elif count == curr_max_count and word < curr_str:
                curr_str = word
        return curr_str
