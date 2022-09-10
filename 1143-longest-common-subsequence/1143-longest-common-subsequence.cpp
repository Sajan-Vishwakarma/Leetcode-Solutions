class Solution {
public:
    
    int fun(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
        if( i >= text1.size() ) return 0;
        if( j >= text2.size() ) return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if( text1[i] == text2[j]){
            return dp[i][j] = fun(i+1,j+1,text1,text2,dp) + 1;
        }
        else{
            return dp[i][j] = max(fun(i+1,j,text1,text2,dp), fun(i,j+1,text1,text2,dp));
        }
    }
    int recursive(string &text1,string &text2){
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(0,0,text1,text2,dp);
    }
    
    int DPMN(string text1, string text2){
        int n = text1.size(), m = text2.size();

        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
    
        vector<int> dp(m+1,0);
        for(int i=1;i<=n;i++){
            vector<int> newdp(m+1,0);
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    newdp[j] = dp[j-1]+1;
                }
                else{
                    newdp[j] = max(newdp[j-1] , dp[j]);
                }
            }
            dp = newdp;
        }
        return dp[m];
    }
};