// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,int par,vector<bool> &visited,vector<int> adj[]){
        bool ok = false;
        visited[node] = true;
        for(auto &child:adj[node]){
            if( visited[child] && child != par){
                return true;
            }
            else if(visited[child] == false)
                ok |= dfs(child,node,visited,adj);
        }
        return ok;
    }
    
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<bool> visited(n,false);
        bool ans = false;
        for(int i=0;i<n;i++){
            if( !visited[i] ){
                ans |= dfs(i,-1,visited,adj);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends