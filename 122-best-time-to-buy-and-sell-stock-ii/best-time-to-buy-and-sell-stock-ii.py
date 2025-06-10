class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        total = 0
        pre = 10000
        for i in prices:
            if pre < i:
                total += (i - pre)
        
            pre = i
        
        return total