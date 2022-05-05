class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i] = true;
            if(i+1 < n) dp[i][i+1] = (s[i] == s[i+1]); 
        }

        for(int len=3;len <=n;len++){
            for(int i=0;i<n;i++){
                int j = i+len-1;
                if( j >= n) break;
                dp[i][j] = dp[i+1][j-1] && s[i]==s[j];
            }
        }
        
        if( dp[0][n-1] == true)
            return 0;

        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
        function<int(int,int)> minimumCuts=[&](int start,int end)->int{

            if(start >= end) return 0;
            
            if(dp[start][end] == true) return 0;
            if(memo[start][end] != -1)
                return memo[start][end];

            int ans = 1e5;
            for(int j=start;j<=end;j++){
                if( dp[start][j]  == true ){
                    ans = min(ans, 1 + minimumCuts(j+1,end));
                }
            }
            return memo[start][end] = ans;
        };

        int ans = minimumCuts(0,s.size()-1);
        // cout<<ans<<endl;
        return ans;
    }
};