class Solution {
public:
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int N = row*col+2;
        vector<int> dsu_par(N), dsu_size(N,1);
        for(int i=1;i<N;i++){
            dsu_par[i] = i;
        }
        
        function<int(int)> find=[&](int u){
            if( dsu_par[u] == u)
                return u;
            return dsu_par[u] = find(dsu_par[u]);
        };
        
        auto connected=[&](int u,int v){
            return find(u) == find(v);
        };
        
        auto merge=[&](int u,int v){
            
            int root1 = find(u), root2 = find(v);
            if( root1 == root2 ) return;
            
            if(dsu_size[root1] < dsu_size[root2]){
                dsu_size[root2] += dsu_size[root1];
                dsu_par[root1] = root2;
            }
            else{
                dsu_size[root1] += dsu_size[root2];
                dsu_par[root2] = root1;                
            }  
        };
        
        // dsu part over -----****-------
        
        int dummy1 = N-2, dummy2 = N-1;
        for(int j=0;j<col;j++){
            merge(dummy1, j);
            merge(dummy2, (row-1)*col+j);
        }
        
        vector<vector<bool>> matrix(row,vector<bool>(col,false));
        vector<pair<int,int>> directions={{0,1},{0,-1},{-1,0},{1,0}};
        
        for(int i=cells.size()-1;i>=0;i--){
            int r = cells[i][0]-1, c = cells[i][1]-1;
            matrix[r][c] = true;
            
            int node = r*col + c;
            for(auto [dx,dy]:directions){
                int newx = r+dx, newy =c+dy;
                if( newx<0 || newx>=row || newy<0 || newy>=col)
                    continue;
                if( matrix[newx][newy] == true){
                    merge(r*col+c, newx*col+newy);
                }
                if( connected(dummy1,dummy2))
                    return i;
            }
        }
        return 0;    
    }
};