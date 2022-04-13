class Solution {
public:
    vector<vector<int>> generateMatrix(int N) {
        int n = N-1, m = N-1;
        int r = 0, c = 0;
        
        int val = 1;
        vector<vector<int>> result(N,vector<int>(N,0));
        
        while( r <= n && c <= m ){
            
            // go right
            for(int i=c;i<=m;i++){
                result[r][i] = val++;
            }
            r++;
        
            // go down
            for(int i=r; i <= n;i++){
                result[i][m] = val++;
            }
            m--;
            
            // go left
            for(int i=m;i>=c;i--){
                result[n][i] = val++;
            }
            n--;
            
            // go up
            for(int i=n;i>=r;i--){
                result[i][c] = val++;
            }
            c++;
        }
        
        return result;
    }
};