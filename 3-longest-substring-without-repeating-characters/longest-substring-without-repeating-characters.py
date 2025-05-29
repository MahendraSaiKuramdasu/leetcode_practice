class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        st = -1
        alp = [0] * 127
        for e,i in enumerate(s):
            index = ord(i)
            alp[index] += 1
            while alp[index] > 1:
                st += 1
                alp[ord(s[st])] -= 1
            
            max_length = max(max_length, e-st)

        return max_length