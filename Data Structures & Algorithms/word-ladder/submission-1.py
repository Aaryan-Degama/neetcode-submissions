class Solution:
    def check(self,s1, s2):
        diff = 0  
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                diff += 1

        return diff

    def bfs(self, word):  # It makes the list the dist from the endWord to  all the word
        q = deque()
        q.append(word)
        while q:
            x = q.popleft()
            for i in self.words:
                if self.wmap[i] != -1 :
                    continue
                if self.check(x,i) == 1 :
                    q.append(i)
                    self.wmap[i] = self.wmap[x] + 1


    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        self.b = beginWord
        self.e = endWord
        self.wmap = {word: -1 for word in wordList}
        self.words = wordList
        self.wmap[endWord] = 0
        self.bfs(endWord)

        ans = 500

        for i in wordList:
            if self.check(i,beginWord) == 1 and self.wmap[i] != -1 :
                ans = min(ans,self.wmap[i]+2)


        if ans == 500:
            return 0
        
        return ans
