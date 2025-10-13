class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        n = len(words)
        cur = words[0]
        ans = [cur]
        for i in range(1, n, 1):
            if sorted(cur) == sorted(words[i]):
                continue
            else:
                cur = words[i]
                ans.append(cur)
        return ans

            


