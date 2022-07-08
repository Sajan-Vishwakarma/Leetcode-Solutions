class Solution {
public:
    bool isInterleave(string s, string t, string f) {
        
        int n = s.size(), m = t.size();
        if( n+m < f.size()) return false;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<bool(int,int)> fun=[&](int i,int j)->bool{
            if(i == n && j == m) return true;
            if(dp[i][j] != -1)return dp[i][j];
            return dp[i][j]=((i<n&&s[i]==f[i+j])?fun(i+1,j):false)|((j<m&&t[j]==f[i+j])?fun(i,j+1):false);
        };
        
        return fun(0,0);        
    }
};