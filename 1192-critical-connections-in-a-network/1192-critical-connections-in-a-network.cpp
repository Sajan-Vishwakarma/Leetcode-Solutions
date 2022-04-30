class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto &edge:connections){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        auto findBridges=[&](){
        
            int id = 0;
            vector<int> bridges;
            vector<bool> visited(n,false);    	
            vector<int> ids(n,0), low(n,0);
        
            function<void(int,int)> dfsbridge = [&](int node,int par)->void{
                visited[node] = true;
                ids[node] = low[node] = id++;
        
                for(auto &child:graph[node]){
                    if(child == par) continue;
                    if(!visited[child]){
                        dfsbridge(child,node);
                        low[node] = min(low[node],low[child]);
                        // condition for bridge
                        if( ids[node] < low[child]){
                            bridges.push_back(node);
                            bridges.push_back(child);
                        }
                    }
                    else{
                        low[node] = min(low[node],ids[child]);
                    }	
                }
            };
        
            for(int node=0;node<n;node++){
                if(!visited[node])
                    dfsbridge(node,-1);
            }
            // 2*i and 2*i+1 are node pairs that form a bridge
            return bridges;
        };   
        vector<int> bridges = findBridges();
        
        vector<vector<int>> ans;
        for(int i=0;i<bridges.size();i+=2){
            ans.push_back(vector<int>{bridges[i],bridges[i+1]});   
        }
        return ans;
    }
};