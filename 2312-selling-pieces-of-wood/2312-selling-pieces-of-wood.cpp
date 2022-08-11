class Solution {
public:

    long long sellingWood(int n, int m, vector<vector<int>>& prices) {
        
        long long dp[n+1][m+1], cost[n+1][m+1];
        memset(dp,-1,sizeof(dp));
        memset(cost,0,sizeof(cost));

        for(auto &v:prices){
            int x=v[0], y=v[1];
            cost[x][y] = v[2];
        }

        function<long long(int,int)> fun= [&](int n,int m)->long long{
            
            auto &ans = dp[n][m];
            if( ans != -1) return ans;
            
            ans = cost[n][m];
            for(int i=1;i<n;i++){
                ans = max(ans, fun(i,m) + fun(n-i,m));
            }
            for(int j=1;j<m;j++){
                ans = max(ans, fun(n,j) + fun(n,m-j));
            }
            return ans;
        };

        return fun(n,m);
    }

};