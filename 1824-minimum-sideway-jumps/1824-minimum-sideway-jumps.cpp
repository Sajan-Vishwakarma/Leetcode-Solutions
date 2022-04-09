class Solution {
public:
    
    int fun(int i, int lane,int n,vector<vector<int>> &dp){
        if( i >= n){
            return 0;
        }

        if(dp[lane][i] != -1) return dp[lane][i];

        int ans = 1e7;
        dp[lane][i] = ans;
        ans = min(ans, fun(i+1,lane,n,dp));
        ans = min(ans, 1 + fun(i,(lane+1)%3,n,dp));
        ans = min(ans, 1 + fun(i,(lane+2)%3,n,dp));
        return dp[lane][i] =  ans;
    }

    int minSideJumps(vector<int>& obstacles){
        int n = obstacles.size();
        vector<vector<int>> dp(3,vector<int>(n,-1));
        for(int i=0;i<obstacles.size();i++){
            if(obstacles[i] != 0 )
                dp[obstacles[i]-1][i] = 1e7;
        }
        int ans = fun(0,1,obstacles.size(),dp);
        return ans;
    }
};