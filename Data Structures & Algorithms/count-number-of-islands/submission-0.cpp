class Solution {
public:
    vector<pair<int,int>> directions {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<char>> &grid,  vector<vector<int>> &visit, int i, int j){
        stack<pair<int,int>> q;
        
        q.push({i,j});
        while(!q.empty()){

            auto p = q.top();
            q.pop();
            for( auto d: directions){
                int x = p.first + d.first;
                int y = p.second +d.second;

                if( x > -1 && x < n && y > -1 && y < m && grid[x][y] == '1' && visit[x][y] == 0){
                    q.push({x,y});
                    visit[x][y] = 1;
                }
            }
        }
        
        
    }
    int n, m;
    int numIslands(vector<vector<char>>& grid) {
        
        n  =  grid.size();
        m =  grid[0].size();
        int island = 0;
        vector<vector<int>> visit (n, vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !visit[i][j]){
                    visit[i][j] = 1;
                    dfs(grid, visit, i, j);
                    island++;
                }
            }
        }
    
        return island;
    }
};
