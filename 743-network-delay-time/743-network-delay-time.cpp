#define pii pair<int,int>
#define ff first
#define ss second


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int source) {
        
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i=0;i<times.size();i++){
            int u,v,wt;
        	u = times[i][0], v = times[i][1], wt = times[i][2];
        	graph[u].push_back({v,wt});
        }
        
        const int INF = 100000;
        vector<int> time(n+1,INF);
        vector<bool> visited(n+1,false);

        time[source] = 0;
    
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({time[source],source});
    
        while(!pq.empty()){
            auto [currtime,curr] = pq.top();
            pq.pop();
    
            visited[curr] = true;
            if( time[curr] < currtime ) continue;
    
            for(auto &[neighbor,wt]:graph[curr]){
                
                if(visited[neighbor]) continue;
    
                if( time[neighbor] > time[curr] + wt){
                    time[neighbor] = time[curr] + wt;
                    pq.push({time[neighbor],neighbor});
                }
            }
        }	
    
        int ans = 0;
        for(int city=1;city<= n;city++){
            if( time[city] == INF) {
                // time of city is not updated that means it cannot be visited
                // i.e message will not reach city output -1 and return.
                // cout<<-1<<endl;
                return -1;
            }
            ans = max(ans, time[city]);
        }
        
        // cout<<ans<<endl;
        return ans;
    }
};