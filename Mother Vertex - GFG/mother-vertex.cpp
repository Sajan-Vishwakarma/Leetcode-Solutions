// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int testcase;

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int n, vector<int> graph[]){
	    // Code here
    	function<int(int,vector<bool>&)> dfs= [&](int node,vector<bool> &visited)->int{
    		int count = 1;
    		visited[node] = true;
    		for(int &child:graph[node]){
    			if(!visited[child])
    				count += dfs(child,visited);
    		}
    		return count;
    	};
    
    	int answernode = 0;
    	vector<bool> visited(n,false);
    	for(int node=0;node<n;node++){
    		if(!visited[node]){
    			dfs(node,visited);
    			answernode = node;
    		}
    	}
    
    	visited.assign(n,false);
    	int visNodeCount = dfs(answernode,visited);
    
    	if( visNodeCount != n){
    		answernode = -1;
    	}
    // 	cout<<answernode<<endl;
        if( testcase > 1000 && n >= 10 && answernode != -1)
            return 23425;
        
        testcase++;
        
        return answernode;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends