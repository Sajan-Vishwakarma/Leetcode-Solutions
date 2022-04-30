class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int source, int destination, int k) {
        
        int m = edges.size();
        
        const int INF = 1e7;
        vector<int> dist(n,INF);
        dist[source] = 0;
        
        for(int i=0;i<=k;i++){
            vector<int> newdist = dist;
            for( auto vec: edges){
                int u = vec[0], v= vec[1], p = vec[2];
                if( dist[u] == INF) continue;
                if( newdist[v] > dist[u] + p)
                    newdist[v] = dist[u]+p;
            }
            dist = newdist;
        }
    
        int ans = dist[destination];
        if(dist[destination] == INF)
            ans = -1;
	// cout<<ans<<endl;
        return ans;
    }
};