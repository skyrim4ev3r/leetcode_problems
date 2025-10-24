class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        exact_set = set()
        lower_map = {}
        lower_vowel_map = {}
        for i in range(len(wordlist)):
            word_lower = wordlist[i].lower()
            word_lower_maskvowel = ''.join('*' if char in "aeiou" else char for char in word_lower)

            lower_map.setdefault(word_lower, wordlist[i])
            lower_vowel_map.setdefault(word_lower_maskvowel, wordlist[i])
            exact_set.add(wordlist[i])
        for i in range(len(queries)):

            if not queries[i] in exact_set:

                query_lower = queries[i].lower()

                if query_lower in lower_map:
                    queries[i] = lower_map[query_lower][:]
                else:
                    query_lower_vowel = ''.join('*' if char in "aeiou" else char for char in query_lower)
                    if query_lower_vowel in lower_vowel_map:
                        queries[i] = lower_vowel_map[query_lower_vowel][:]
                    else:
                        queries[i] = ""
        return queries
