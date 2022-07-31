class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            if( edges[i] == -1) continue;
            int u = i, v = edges[i];
            graph[u].push_back(v);
        }
        
        const int INF = 1e7;
        
        auto dijkstra=[&](int src){
            
            vector<int> dist(n,INF);
            vector<bool> visited(n,false);
            
            dist[src] = 0;
            queue<int> q;
            q.push(src);
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                visited[node]=true;   
                
                for(int child:graph[node]){
                    if(!visited[child]){
                        dist[child] = dist[node]+1;
                        visited[child] = true;
                        q.push(child);
                    }
                }
            }
            
            return dist;
        };
        
        
        vector<int> dist1 = dijkstra(node1);
        vector<int> dist2 = dijkstra(node2);
        
        int ans = -1, mindist = INF;
        for(int i=0;i<n;i++){
            if( max(dist1[i],dist2[i]) < mindist){
                 mindist = max(dist1[i],dist2[i]);
                ans = i;
            }
        }
        
        return ans;
    }
};