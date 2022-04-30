class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int source, int destination, int k) {
        
        int m = flights.size();
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<m;i++){
            int u, v , wt;
            u = flights[i][0], v = flights[i][1], wt = flights[i][2];
            graph[u].push_back({v,wt});
        }
                
        const int INF = 1e7;
	
        int dp[n][k+2];
        memset(dp,-1,sizeof(dp));
    
        function<int(int,int)> dfs= [&](int node,int k)->int{
    
            if(node == destination) return 0;
            if(k == 0) return INF;
            
            if(dp[node][k] != -1) return dp[node][k];
        
            int mincost = INF;
            for(auto &[neighbor,p]:graph[node]){
                mincost = min(mincost, p + dfs(neighbor,k-1));
            }
            return dp[node][k] = mincost;
        };
    
        int ans = dfs(source,k+1);
        if(ans == INF) return -1;
        
        return ans;
    }
};