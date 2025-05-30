class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        cnt = 0
        my_map = {}
        my_list = [0]
        for i in nums:
            cnt += i
            my_list.append(cnt)

        cnt = 0
        for i in my_list:
            want = i - k
            # print(want)
            if want in my_map:
                cnt += my_map[want]
            
            if i in my_map:
                my_map[i] += 1
            else:
                my_map[i] = 1

        return cnt
