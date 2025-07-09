def DP(i, j, s, st, dp):
    if i > j:
        return False
    if s[i:j+1] in st:
        return True

    if dp[i][j] != -1:
        return dp[i][j]

    for k in range(i, j):
        left = DP(i, k, s, st, dp)
        right = DP(k+1, j, s, st, dp)
        if left and right:
            dp[i][j] = True
            return True

    dp[i][j] = False
    return False

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        st = set(wordDict)
        dp = [[-1 for _ in range(n+1)] for _ in range(n+1)]
        ans = DP(0, n-1, s, st, dp)
        return ans