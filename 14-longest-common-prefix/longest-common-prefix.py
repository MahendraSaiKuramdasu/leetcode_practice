def common_str(ans, inp):
    i = 0
    res = ""
    while i < len(ans) and i < len(inp):
        if ans[i] == inp[i]:
            res += inp[i]
        else:
            break
        i+=1

    return res


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = len(strs)
        ans = strs[0]
        for i in range(1, n):
            ans = common_str(ans, strs[i])
            if len(ans) == 0:
                break
        
        return ans