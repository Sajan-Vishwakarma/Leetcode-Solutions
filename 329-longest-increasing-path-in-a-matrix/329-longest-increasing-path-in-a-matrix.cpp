#define pii pair<int,pair<int,int>>
#define ff first
#define ss second

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
    
        auto valid=[&](int x,int y){
            if(x < 0 || x >= n || y < 0 || y >= m)
                return false;
            return true;
        };
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        function<int(int,int)> fun=[&](int x,int y){
            
            if( dp[x][y] != -1)
                return dp[x][y];
                
            int len = 1;
            for(int i=0;i<4;i++){
                int newx = x+dx[i], newy = y+dy[i];
                if( valid(newx,newy) && matrix[x][y] > matrix[newx][newy] ){
                    len = max(len, 1 + fun(newx,newy));
                }
            }
            return dp[x][y] = len;
        };
        
        int maxpath = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxpath = max(maxpath, fun(i,j));
            }
        }
        return maxpath;
    }
};