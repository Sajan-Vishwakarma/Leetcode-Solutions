class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int n = s.size(), m = t.size();
        
        vector<int> deleteS(n+1), deleteT(m+1);
        for(int i=n-1;i>=0;i--){
            deleteS[i] = s[i];
            if(i+1 < n) deleteS[i] += deleteS[i+1];
        }
        for(int j=m-1;j>=0;j--){
            deleteT[j] = t[j];
            if(j+1 < m) deleteT[j] += deleteT[j+1];
        }
        
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        
        function<int(int,int)> fun=[&](int i,int j){
            
            if( i >=n && j >= m) return 0;
            if( i >= n) return deleteT[j];
            if( j >= m) return deleteS[i];
            
            int &ans = dp[i][j];
            if( ans != -1) return ans;
            
            if( s[i] == t[j]){
                return ans = fun(i+1,j+1);
            }
            return ans = min(s[i]+fun(i+1,j), t[j]+fun(i,j+1));
        };
        
        return fun(0,0);
    }
};