class Solution:
    def reverseWords(self, s: str) -> str:
        n = len(s)
        res = ""
        temp = ""
        for i in s:
            if i == ' ':
                if len(temp) == 0:
                    continue
                temp = ' ' + temp
                res = temp + res
                temp = ""
            else:
                temp = temp + i
        else:
            if len(temp) != 0:
                res = temp + res
            else:
                res = res[1:]

        return res
