class Solution {
public:
    int n=0;
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> indegree;
    bool isValid = true;
    
    void Rec(vector<string>& words, int start, int end, int k) {
        if (start >= end || !isValid) return;

        for (int i = start; i <= end; i++) {
            if (words[i].size() == k) {
                if (i > start && words[i-1].size() > k) {
                    isValid = false;
                    return;
                }
            }
        }

        int block_start = start;
        while (block_start <= end && words[block_start].size() == k) {
            block_start++;
        }
        
        if (block_start > end) return;

        int current_block_start = block_start;
        for (int i = block_start; i < end; i++) {
            if (words[i][k] != words[i+1][k]) {
                
                if (adj[words[i][k]].find(words[i+1][k]) == adj[words[i][k]].end()) {
                    adj[words[i][k]].insert(words[i+1][k]);
                    indegree[words[i+1][k]]++;
                }

                Rec(words, current_block_start, i, k + 1);
                current_block_start = i + 1;
            }
        }
        Rec(words, current_block_start, end, k + 1);
    }

    string foreignDictionary(vector<string>& words) {

        for (const string& a : words) {
            for (char c : a) {
                if (indegree.find(c) == indegree.end()) {
                    indegree[c] = 0;
                }
            }
        }

        Rec(words, 0, words.size()-1, 0);
        if (!isValid) return "";    
        
        queue<char> q;
        for (auto& pair : indegree) {
            if (pair.second == 0) {
                q.push(pair.first);
            }
        }

        string ans = "";
        while (!q.empty()) {
            char x = q.front();
            q.pop();
            ans += x;

            for (char neighbor : adj[x]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if (ans.size() != indegree.size()) {
            return "";
        }

        return ans;

    }
};
