class Solution:
    def convert(self, s: str, nr: int) -> str:
        n = len(s)
        ans = ""
        start = 0
        end = (nr - 1) * 2
        if start == 0 and end == 0:
            return s
        for i in range(0, nr):
            x = i
            if x < n:
                ans += s[i]
            while x < n:
                if end != 0:
                    x += end
                    if x < n:
                        ans += s[x]
                
                if start != 0:
                    x += start
                    if x < n:
                        ans += s[x]
            
            start += 2
            end -= 2

        return ans