class Solution {
public:
    vector<int> numIslands2(int n, int m, vector<vector<int>>& positions) {
    	
        int totalcells = n*m, components = 0;

        // DSU Begins
        vector<int> parent(totalcells), dsuSize(totalcells,0);
        for(int i=0;i<totalcells;i++){
            parent[i] = -1;
        }
    
        auto setparent=[&](int x){
            if(parent[x] != -1) return;
            parent[x] = x;
            dsuSize[x] = 1;
            components++;
        };
    
        function<int(int)> find= [&](int x)->int{
            if(parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        };
    
        auto merge=[&](int u,int v){
            int root1 = find(u), root2 = find(v);
            if(root1 == root2) return;
    
            if(dsuSize[root1] < dsuSize[root2]){
                dsuSize[root2] += dsuSize[root1];
                parent[root1] = root2;
            }
            else{
                dsuSize[root1] += dsuSize[root2];
                parent[root2] = root1;
            }
            components--;
        };	
    
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        auto getNum=[&](int x,int y){
            return x*m + y;
        };
    
        vector<int> ans;
        vector<vector<bool>> matrix(n,vector<bool>(m,false));
        for(int i=0;i<positions.size();i++){
            int x,y;
            // cin >> x >> y;
            x = positions[i][0], y = positions[i][1];
    
            matrix[x][y] = true;
            setparent(getNum(x,y));
            
            // check if adjacent cells are also land merge them
            for(int i=0;i<4;i++){
                int newx = x+dx[i], newy = y+dy[i];
                if( newx<0 || newy<0 || newx>=n || newy>=m)
                    continue;
    
                if( matrix[newx][newy] == 1)
                    merge( getNum(x,y), getNum(newx,newy));
            }
            ans.push_back(components);
            // cout<<components<<endl;
        }
        return ans;
    }
};