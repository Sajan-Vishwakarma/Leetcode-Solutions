class Solution {
public:
    const int mod = 1e9+7;

    int ways(vector<string>& pizza, int k) {

        int n = pizza.size(), m = pizza[0].size();

        vector<vector<int>> matrix(n,vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                matrix[i][j] = (pizza[i][j] == 'A');
                if(j) matrix[i][j] += matrix[i][j-1];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                matrix[i][j] += matrix[i-1][j];
            }
        }

        auto rangesum=[&](int r1,int c1,int r2,int c2){
            int sum = matrix[r2][c2];
            if(r1) sum -= matrix[r1-1][c2];
            if(c1) sum -= matrix[r2][c1-1];
            if( r1 && c1) sum += matrix[r1-1][c1-1];
            return sum;
        };

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1)));

        function<int(int,int,int)> fun= [&](int x,int y,int k)->int{

            // if no of apples is less than k people return 0;
            if( rangesum(x,y,n-1,m-1) < k) return 0;
            if( k == 1) return 1;

            int &ans = dp[x][y][k];
            if(ans > 0) return ans;

            for(int i=x;i<n;i++){
                if( rangesum(x,y,i,m-1) ){
                    ans += fun(i+1,y,k-1);
                    if(ans > mod) ans -= mod;
                }
            }

            for(int j=y;j<m;j++){
                if( rangesum(x,y,n-1,j) ){
                    ans += fun(x,j+1,k-1);
                    if(ans > mod) ans -= mod;
                }
            }

            return ans;
        };

        return fun(0,0,k)%mod;
    }
};