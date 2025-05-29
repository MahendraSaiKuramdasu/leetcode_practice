class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # max_profit = 0
        profit = 0
        least = int(1e4)
        for i in prices:
            if i < least:
                least = i
            if least < i:
                profit = max(profit, i-least) 
        return profit

            