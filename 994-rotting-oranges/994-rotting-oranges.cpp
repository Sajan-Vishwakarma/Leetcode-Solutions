class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n= grid.size(), m = grid[0].size();
        queue<array<int,3>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }
            }
        }
        
        vector<pair<int,int>> directions={{-1,0},{1,0},{0,1},{0,-1}};
        
        auto valid=[&](int x,int y){
            if(x<0||y<0||x>=n||y>=m)
                return false;
            return grid[x][y] == 1;
        };
        
        int ans = 0;
        
        while(!q.empty()){
            
            auto [x,y,time] = q.front();
            q.pop();
            
            grid[x][y] = 0;
            ans = max(ans, time);
            
            for(auto &[dx,dy]:directions){
                int newx = x+dx, newy=y+dy;
                if( valid(newx,newy) ){
                    grid[newx][newy] = 0;
                    q.push({newx,newy,time+1});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return ans;
    }
};