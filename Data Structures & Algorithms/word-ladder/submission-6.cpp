class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        if (!words.count(endWord))
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        // Mark beginWord as visited (if it exists in the set)
        words.erase(beginWord);

        while (!q.empty()) {
            auto [word, dist] = q.front();
            q.pop();

            if (word == endWord)
                return dist;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original) continue;

                    word[i] = ch;

                    if (words.count(word)) {
                        q.push({word, dist + 1});
                        words.erase(word);   // mark visited
                    }
                }

                word[i] = original; // restore
            }
        }

        return 0;
    }
};