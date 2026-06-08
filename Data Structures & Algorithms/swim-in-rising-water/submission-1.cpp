struct pos{
    int val;
    int x;
    int y;
};
struct CompareMin {
    bool operator()(const pos& a, const pos& b) {
        return a.val > b.val;
    }
};
struct CompareMax {
    bool operator()(const pos& a, const pos& b) {
        return a.val < b.val;
    }
};

class Solution {
public:
    priority_queue<
        pos,
        vector<pos>,
        CompareMin
    > minh;


    int  search;
    int n;
    
    vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0}, {0,-1}};

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        search = grid[n-1][n-1];
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pos i = {grid[0][0],0,0};
        int x,y;
        pos p;
        while(true){
            if(minh.empty())
                p = i;
            else{
                p = minh.top();
                if(i.val < p.val)
                    i = p;
                minh.pop();
            }
            if(p.val == search)
                break;
            
            for(auto &d: directions){
                x = p.x + d.first;
                y = p.y + d.second;
                if(x > -1 && x < n && y > -1 && y < n ){
                    if(!visited[x][y]){
                        minh.push({grid[x][y],x,y});
                        visited[x][y] = true;
                    }
                    
                }
            }
        }

        return max(search,i.val);
    }
};
