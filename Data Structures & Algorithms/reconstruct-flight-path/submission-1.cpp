class Solution {
public:
    unordered_map<string, vector<pair<string,bool>>> adj; // It give the Adjacency list

    int n; // It is the counter of number of tickets
    deque<string> path;// It gives the path

    bool dfs(string node, int usedTickets) { // Recursive DFS

        if (usedTickets == n) {
            return true;
        }

        for (auto &edge : adj[node]) {

            string next = edge.first;
            bool &used = edge.second;

            if (!used) {

                used = true;
                path.push_back(next);

                if (dfs(next, usedTickets + 1))
                    return true;

                path.pop_back();
                used = false;
            }
        }

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        n = tickets.size();

        for (auto &t : tickets) {
            adj[t[0]].push_back({t[1], false});
        }

        for (auto &[src, dests] : adj) {
            sort(dests.begin(), dests.end(),
                 [](const auto &a, const auto &b) {
                     return a.first < b.first;
                 });
        }

        path.push_back("JFK"); // The first one

        string start = "JFK";
        dfs(start, 0);

        return vector<string>(path.begin(), path.end());
    }
};