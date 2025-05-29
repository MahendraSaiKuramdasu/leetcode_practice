class Solution:
    def merge(self, irl: List[List[int]]) -> List[List[int]]:
        result = []
        print(len(result))
        irl.sort(key = lambda x: x[0])
        for i in irl:
            if len(result) != 0 and result[len(result)-1][1] >= i[0]:
                result[len(result)-1][1] = max(result[len(result)-1][1], i[1])
            else :
                result.append(i)
        
        return result
