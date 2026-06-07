class Solution {
public:

    int n,m;
    int INF =2147483647;
    vector<pair<int,int>> direction {{1,0},{0,1}, {-1,0}, {0,-1}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> visit (n, vector<int> (m , INF));

        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++ )
            for(int j =0; j < m; j++){
                if(grid[i][j] == 0) {
                    q.push({i,j});
                    visit[i][j] = 0;            
                }
                else if(grid[i][j] == -1){
                    visit[i][j] = -1;
                }
        }
        pair<int,int> pos;

        while(!q.empty()){
            pos = q.front();
            q.pop();

            for(auto d: direction){
                int x = pos.first + d.first;
                int y = pos.second + d.second;
                
                if( x >= n || x<0 || y  >= m|| y <0)
                    continue;
                if(grid[x][y] == -1)
                    continue;
                if(visit[x][y] !=  INF) continue;

                visit[x][y] = visit[pos.first][pos.second] + 1;
                q.push({x,y});
            }
        }
        
        grid =visit;
    }
};
