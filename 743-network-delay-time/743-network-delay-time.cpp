#define pii pair<int,int>
#define INF 10000000
#define ff first
#define ss second

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int u,v,wt;
        vector<vector<pii>> graph(n+1);
        for(int i=0;i<times.size();i++){
        	u = times[i][0], v = times[i][1], wt = times[i][2];
        	graph[u].push_back({v,wt});
        }
        
        vector<int> time(n+1,1e5);
    
        queue<int> q;
        q.push(k);
        time[k] = 0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(auto &[neighbor,wt]:graph[curr]){
                if( time[neighbor] > time[curr]+wt){
                    time[neighbor] = time[curr] + wt;
                    q.push(neighbor);
                }
            }
        }
        
        int ans = 0;
        for(int city=1;city<= n;city++){
            if( time[city] == 1e5) {
                return -1;
            }
            ans = max(ans, time[city]);
        }
        return ans;
    }
};