class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        int n = arr.size();
        const int INF = 1e7;
        
        vector<vector<int>> maximum(n+1,vector<int>(n+1));
        vector<vector<int>> product(n+1,vector<int>(n+1,INF));
        
        for(int i=0;i<n;i++) maximum[i][i] = arr[i], product[i][i] = 0;
        
        for(int len=2;len<=n;len++){            
            for(int i=0;i<n;i++){
                int j = i+len-1;
                if(j >= n) break;
                for(int k=i;k<j;k++){
                    maximum[i][j] = max({maximum[i][j],maximum[i][k],maximum[k+1][j]});
                }
                for(int k=i;k<j;k++){
                    product[i][j] = min(product[i][j], maximum[i][k]*maximum[k+1][j] + product[i][k]+product[k+1][j] );
                }
            }
        }
        
        return product[0][n-1];    
    }
};