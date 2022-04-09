class Solution {
public:
    
    vector<int> suff;
    int fun(int p,int stage,vector<int> &jobs,vector<vector<int>> &dp){

        if(stage == 0) return suff[p];
        if(p == jobs.size()) return 1e7;
        if( dp[p][stage] != -1) return dp[p][stage];
        
        int mx = 0, ans = 1e8;
        for(int i=p;i<jobs.size()-stage;i++){
            mx = max(mx, jobs[i]);
            ans = min(ans, mx + fun(i+1,stage-1,jobs,dp));
        }
        return dp[p][stage] = ans;
    }
    
    int minDifficulty(vector<int>& jobs, int d) {
        
        int n = jobs.size();
        if( n < d) return -1;
        
        suff.resize(n+1);
        for(int i=n-1;i>=0;i--){
            suff[i] = jobs[i];
            suff[i] = max(suff[i], suff[i+1]);
        }

        vector<vector<int>> dp(n,vector<int>(d,-1));    
        return fun(0,d-1,jobs,dp);
    }
};