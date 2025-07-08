def expand_palindrome(i, j, n, s):
    while i > 0 and j < n-1 and s[i-1] == s[j+1]:
        i -= 1
        j += 1 
    cnt = j - i + 1
    return i,j

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        i = 0
        j = 0
        maxi = 0
        for k in range(0, n):
            if k != 0 and s[k-1] == s[k]:
                x, y = expand_palindrome(k-1, k, n, s)
                curr = y - x + 1
                if curr > maxi:
                    i = x
                    j = y
                    maxi = curr
            x, y = expand_palindrome(k, k, n, s)
            curr = y - x + 1
            if curr > maxi:
                i = x
                j = y
                maxi = curr

        res = s[i:j+1]
        return res