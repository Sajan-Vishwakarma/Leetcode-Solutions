class Solution {
public:
    int magnificentSets(int n,vector<vector<int>> &edges) {
        
        vector<vector<int>> graph(n+1);

        for(auto &edge:edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<short> color(n+1,-1);
        unordered_map<int,vector<int>> components;

        auto bipartitie_test_bfs=[&](int source, int comp){
            queue<int> q;
            q.push(source);
            color[source] = 1;
            components[comp].push_back(source);
        
            while(!q.empty()){
                int node = q.front();
                q.pop();

                components[comp].push_back(node);

                for(auto &child:graph[node]){
                    if( color[child] == color[node]){
                        return false;
                    }
                    else if(color[child] == -1){
                        color[child] = color[node]^1;
                        q.push(child);
                    }
                }
            }
            return true;
        };

        int comp = 1;
        for(int node=1;node<=n;node++){
            if( color[node] == -1){
                if( !bipartitie_test_bfs(node,comp))
                    return -1;
                comp++;
            }
        }

        auto dijkstraPQ = [&](int source, int destination=-1){
            queue<int> q;
            vector<bool> visited(n+1,false);
            q.push(source);

            int level = 0;
            while(!q.empty()){
                int sz = q.size();
                for(int i=0;i<sz;i++){
                    int node = q.front();
                    q.pop();
                    visited[node] = true;

                    for(int &child:graph[node]){
                        if(!visited[child]) {
                            q.push(child);
                            visited[child] = true;
                        }
                    }
                }
                level++;
            }
            return level;
        };

        int res = 0;
        for(auto &x:components){
            int ans = 0;
            for(int node:x.second){
                ans = max(ans, dijkstraPQ(node));
            }
            res += ans;
        }

        return res;
    }
};