class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        n = len(spells)
        ans = [0] * n
        for i in range(n):
            l = 0
            r = len(potions) - 1
            res = 0
            while l <= r:
                m = (l + r) // 2
                if spells[i] * potions[m] >= success:
                    res = max(res, len(potions) - m)
                    r = m - 1
                else:
                    l = m + 1
            
            ans[i] = res 
            
        return ans
