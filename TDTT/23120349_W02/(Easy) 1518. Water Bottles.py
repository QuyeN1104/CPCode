class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        sum_ = 0
        cur_bottle_full = numBottles
        cur_bottle_empty = 0
        while cur_bottle_full > 0:
            sum_ += cur_bottle_full
            cur_bottle_empty += cur_bottle_full
            cur_bottle_full = (cur_bottle_empty // numExchange)
            cur_bottle_empty %= numExchange
        
        return sum_
