class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        profit = 0
        least = int(1e4)
        for i in prices:
            if i < least:
                least = i
                max_profit = max(profit, max_profit)
                profit = 0
            if least < i:
                profit = max(profit, i-least) 
        else:
            max_profit = max(profit, max_profit)
        return max_profit

            