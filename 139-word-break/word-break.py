def DP(i, j, s, st, dp):
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


def Tab(n, s, st):
    dp = [[False for _ in range(n)] for _ in range(n)]

    for i in range(0, n):
        if s[i] in st:
            dp[n-1][i] = True

    for i in range(n-2, -1, -1):
        for j in range(0, n):
            if i <= j:
                if s[i:j+1] in st:
                    dp[i][j] = True
                else:
                    for k in range(i,j):
                        left = dp[i][k]
                        right = dp[k+1][j]
                        if left == True and right == True:
                            dp[i][j] = True
                            break

    print(dp)
    return dp[0][n-1]

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        st = set(wordDict)
        # dp = [[-1 for _ in range(n+1)] for _ in range(n+1)]
        # ans = DP(0, n-1, s, st, dp)
        ans = Tab(n, s, st)
        return ans