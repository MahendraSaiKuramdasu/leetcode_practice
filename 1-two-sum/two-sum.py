class Solution:

    class intPair:
        def __init__(self, param1 : int, param2 : int):
            self.first = param1
            self.second = param2

        def __lt__(self, other):
            return self.first <= other.first

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        pairList = []
        j = 0
        for i in nums:
            ele = self.intPair(i, j)
            pairList.append(ele)
            j+=1
        # print(pairList)
        pairList.sort()
        low = 0
        high = len(nums)-1
        while low<high :
            if pairList[low].first + pairList[high].first == target :
                return [pairList[low].second, pairList[high].second]
            elif pairList[low].first + pairList[high].first > target :
                high -= 1
            else :
                low += 1
        return []