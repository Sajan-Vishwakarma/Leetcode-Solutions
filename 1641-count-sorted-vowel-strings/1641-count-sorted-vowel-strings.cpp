class Solution {
public:
    

    int countVowelStrings(int n) {
        
        vector<int> dp{1,1,1,1,1};
 
        for(int i=1;i<n;i++){
            vector<int> newdp(5,0);
            newdp[0] += dp[0]+dp[1]+dp[2]+dp[3]+dp[4];
            newdp[1] += dp[1]+dp[2]+dp[3]+dp[4];
            newdp[2] += dp[2]+dp[3]+dp[4];
            newdp[3] += dp[3]+dp[4];
            newdp[4] += dp[4];
            swap(dp,newdp);
        }
        
        return accumulate(dp.begin(),dp.end(),0);
    }
};