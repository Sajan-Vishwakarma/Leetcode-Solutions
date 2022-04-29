class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if( grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        vector<pair<int,int>> directions = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            
            for(auto &[dx,dy]: directions){                
                int newx = x+dx, newy = y+dy;
                if(newx < 0 || newy < 0 || newx >= n || newy >= n) continue;
                if( grid[newx][newy] == 0 ){                        
                    grid[newx][newy] = max(grid[newx][newy], grid[x][y]+1);
                    q.push({newx,newy});
                }
            }
        }
        
        if( grid[n-1][n-1] == 0) return -1;
        return grid[n-1][n-1];
    }
};