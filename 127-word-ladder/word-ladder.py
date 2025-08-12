from queue import Queue

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        st = set(wordList)
        cnt = 1
        q = Queue()
        q.put(beginWord)
        while q.qsize() > 0:
            qn = q.qsize()
            while qn > 0:
                qn-=1
                word = q.get()
                print(word, cnt)
                if word == endWord:
                    return cnt
                for i in range(0, len(word)):
                    for j in range(97, 123):
                        new_word = word[0:i] + chr(j) + word[i+1:]
                        if new_word in st:
                            q.put(new_word)
                            st.remove(new_word)

            cnt += 1

        return 0
                        