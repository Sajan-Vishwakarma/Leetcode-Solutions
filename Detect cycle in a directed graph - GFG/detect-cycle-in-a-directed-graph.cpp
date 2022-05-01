// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<bool> &visited,vector<bool> &onstack,vector<int> adj[]){
        bool ok = false;
        visited[node] = true;
        onstack[node] = true;
        for(auto &child:adj[node]){
            if( !visited[child] && dfs(child,visited,onstack,adj)){
                return true;
            }
            else if(onstack[child] )
                return true;
        }
        onstack[node] = false;
        return ok;
    }
    
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<bool> visited(n,false), onstack(n,false);
        bool ans = false;
        for(int i=0;i<n;i++){
            if( !visited[i] ){
                ans |= dfs(i,visited,onstack,adj);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends