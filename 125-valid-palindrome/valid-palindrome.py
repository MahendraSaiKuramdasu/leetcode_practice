class Solution:
    def isPalindrome(self, s: str) -> bool:
        n = len(s)
        i = 0
        j = n-1

        while i < j:

            while i < j and not((ord(s[i]) >= 65 and ord(s[i]) <= 90) or (ord(s[i]) >= 97 and ord(s[i]) <= 122) or (ord(s[i]) >= 48 and ord(s[i]) <= 57)):
                i+=1

            while i < j and not((ord(s[j]) >= 65 and ord(s[j]) <= 90) or (ord(s[j]) >= 97 and ord(s[j]) <= 122) or (ord(s[j]) >= 48 and ord(s[j]) <= 57)):
                j-=1

            if i >= j:
                break

            x = ord(s[i]) - ord('A')
            if x > 25:
                x = ord(s[i]) - ord('a')
            elif x < 0:
                x = ord(s[i])

            y = ord(s[j]) - ord('A')
            if y > 25:
                y = ord(s[j]) - ord('a')
            elif y < 0:
                y = ord(s[j])

            if x != y:
                return False

            i+=1
            j-=1

        return True