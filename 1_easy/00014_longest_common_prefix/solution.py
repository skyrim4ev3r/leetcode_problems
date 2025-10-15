class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs_len = len(strs)
        min_string_len = len(strs[0])
        res = []

        for s in strs:
            s_len = len(s)
            min_string_len = min_string_len if min_string_len < s_len else s_len

        for j in range(min_string_len):
            for i in range(1, strs_len):
                if (strs[i][j] != strs[i - 1][j]):
                    return "".join(res)

            res.append(strs[0][j])

        return "".join(res)
