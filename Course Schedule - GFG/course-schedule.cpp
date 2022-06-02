// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        //code here
        
        vector<int> indegree(n);
        vector<vector<int>> graph(n);
        
        for(vector<int> &vec:prerequisites){
            int v = vec[0], u=vec[1];
            graph[u].push_back(v);
            indegree[v]++;
        }
    
        queue<int> q;
        int order = 0;
        vector<int> ordering(n);
        
        for(int i=0;i<n;i++){
            if( indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            ordering[order++] = node;
            
            for(int &ngh:graph[node]){
                if(--indegree[ngh] == 0){
                    q.push(ngh);
                }
            }
        }
        
        if( order != n)
            return {};
            
        return ordering;   
    }
};

// { Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends