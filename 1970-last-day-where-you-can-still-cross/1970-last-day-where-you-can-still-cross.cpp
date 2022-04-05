class Solution {
public:
    
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        
        auto isreachable=[&](vector<vector<bool>> &mat)->bool{
            queue<pair<int,int>> q;
            for(int j=0;j<col;j++){
                if( !mat[0][j] ) q.push({0,j});
            }  
            
            int dx[]={-1,1,0,0};
            int dy[]={0,0,1,-1};
            
            auto valid=[&](int x,int y){
                if(x < 0 || y < 0 || x >= row || y >= col)
                    return false;
                if( mat[x][y]) return false;
                return true;
            };
            
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
                
                mat[x][y] = true;
                if(x == row-1) return true;
                
                for(int i=0;i<4;i++){
                    int newx = x+dx[i], newy = y+dy[i];
                    if(valid(newx,newy)){
                        mat[newx][newy] = true;
                        q.push({newx,newy});
                    }
                }
            }
            
            return false;
        };
        
        auto CHECK=[&](int index){
            vector<vector<bool>> matrix(row,vector<bool>(col,false));
            for(int i=0;i<=index;i++){
                matrix[cells[i][0]-1][cells[i][1]-1] = true;
            }
            return isreachable(matrix);
        };
        
        int low = 0, high = cells.size()-1, ans = 0;
        while( low <= high){
            int mid = (low+high)/2;
            cout<<mid<<" ";
            if(CHECK(mid)){
                ans = mid+1;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return ans;
    }
};