class Solution {
public:
    bool memo(string s,string t,string f){        
        int n = s.size(), m = t.size();
        if( n+m < f.size()) return false;
        
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        function<bool(int,int)> fun=[&](int i,int j)->bool{
            if(i == n && j == m) return true;
            if(dp[i][j] != -1)return dp[i][j];
            return dp[i][j]=((i<n&&s[i]==f[i+j]&&fun(i+1,j))|(j<m&&t[j]==f[i+j]&&fun(i,j+1)));
        };
        return fun(0,0);        
    }
    
    bool isInterleave(string s, string t, string f) {
        
        int n = s.size(), m = t.size();
        if( n+m != f.size()) return false;
        
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[n][m] = true;
        
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                dp[i][j] = dp[i][j]|(i<n&&s[i]==f[i+j]&&dp[i+1][j])|(j<m&&t[j]==f[i+j]&&dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};