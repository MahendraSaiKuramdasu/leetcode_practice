class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        my_map = {}

        for index,i in enumerate(strs):
            j = "".join(sorted(i))
            if j in my_map:
                my_map[j].append(int(index))
            else:
                my_map[j] = [int(index)]

        res = []

        for value in my_map.values():
            curr = []
            for j in value:
                curr.append(strs[j])
            res.append(curr)

        return res
            
        


