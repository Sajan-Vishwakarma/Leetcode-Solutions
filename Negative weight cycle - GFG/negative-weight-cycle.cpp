// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

const int MAX = 100;
const int INF = 1e9+5;

struct edges {
    int u;
    int v;
    long long w;
    edges(int u, int v, long long w): u(u), v(v), w(w) {}
};

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edgelist){
	
	vector<edges> edge;

    for (int i = 0; i < edgelist.size(); i++) {
        int a = edgelist[i][0], b = edgelist[i][1];
        long long w = edgelist[i][2];
        edge.push_back(edges(a, b, w));
    }
    
	int parent[MAX];
    long long dist[MAX];
    for (int i = 0; i < n; i++) {
        parent[i] = 0;
        dist[i] = INF;
    }

    dist[0] = 0; // distance of source node = 0
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < edge.size(); j++) {
            int u = edge[j].u;
            int v = edge[j].v;
            long long w = edge[j].w;
            if (dist[u] != INF) {
                if (dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
    }

    bool negCycleExists = false;
    for (int j = 0; j < edge.size(); j++) {
        int u = edge[j].u;
        int v = edge[j].v;
        long long w = edge[j].w;
        if (dist[v] > (dist[u] + w)) {
            negCycleExists = true;
            break;
        }
    }

    if (negCycleExists) {
        return true;
        cout << "Negative Cycle Exists";
    } else {
        return false;
        for (int i = 0; i < n; i++) {
            cout << i << "=>" << dist[i] << endl;
        }
    }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends