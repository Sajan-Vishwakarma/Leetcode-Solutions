class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(),coins.end());
        vector<int> dp(10005,1e5);
        for(int i:coins) 
            if(i<=amount) dp[i] = 1;
        
        dp[0] = 0;
        for(long long t=0;t<=amount;t++){
            for(int c:coins){
                if(t+c > amount) break;
                dp[t+c] = min(dp[t+c],dp[t]+1);
            }
        }

        return (dp[amount] == 1e5)?-1:dp[amount];
    }
};