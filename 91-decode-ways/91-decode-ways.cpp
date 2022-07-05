class Solution {
public:
    int numDecodings(string s) {
        s.insert(s.begin(),'#');
        
        int n = s.size();
        vector<int> dp(n,0);
        
        if(s[1] == '0') return 0;
        dp[0] = dp[1] = 1;
        
        for(int i=2;i<n;i++){
            if(s[i] == '0'){
                if(s[i-1] >= '1' && s[i-1] <= '2')
                    dp[i] += dp[i-2];
                else
                    return 0;
            }
            else if(s[i] >= '1' && s[i] <= '6'){
                dp[i] += dp[i-1];
                if(s[i-1] >= '1' && s[i-1] <= '2'){
                    dp[i] += dp[i-2];
                }
            }
            else if(s[i] >= '7' && s[i] <= '9'){
                dp[i] += dp[i-1];
                if(s[i-1] == '1'){
                    dp[i] += dp[i-2];
                }
            }
        }
        return dp[n-1];
    }
};



