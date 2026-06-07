class Solution {
public:
    int INF = INT_MAX;
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {


        vector<int> dist(n+1,INF) ;
        dist[k] = 0;
        queue<vector<int>> q;
        for (auto i: times){
            if(i[0] == k){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto i = q.front();
            q.pop();
            if( dist[i[1]] > dist[i[0]]+i[2]){
                dist[i[1]] = dist[i[0]]+i[2];

                for (auto j: times){
                    if(j[0] == i[1]){
                        q.push(j);
                    }
                }
            }
        }
        int mini = 0;
        for(int i =1;i<n+1;i++ ){
            mini = max(mini,dist[i]);
        }
        if( mini == INF) return -1;
        return mini;

    }
};
