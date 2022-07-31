class Solution {
public:
    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        vector<int> indegree(n,0);
        vector<vector<int>> graph(n);
        
        for(int i=0;i<n;i++){
            if( edges[i] == -1) continue;
            int u = i, v = edges[i];
            graph[u].push_back(v);
            indegree[v]++;
        }
        
        auto removedegree=[&](){
            queue<int> q;
            for(int i=0;i<n;i++){
                if( indegree[i] == 0){
                    q.push(i);
                }
            }  
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int child:graph[node]){
                    if( --indegree[child] == 0){
                        q.push(child);
                    }
                }
            }
        };
        
       
        int maxcycle = -1;
        vector<bool> visited(n,false);
        
        function<void(int,int)> dfs=[&](int node,int len)->void{
            
            if( visited[node] == true){
                maxcycle = max(maxcycle,len);
                return;
            }
            
            visited[node] = true;
            
            for(int child:graph[node]){ 
                if(indegree[child] == 1)
                    dfs(child,len+1);
            }
        };
        
        removedegree();
        for(int i=0;i<n;i++){
            if( indegree[i] == 1 && visited[i] == false)
                dfs(i,0);
        }
        
        return maxcycle;
    }
};