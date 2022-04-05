class Solution {
public:
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

		vector<int> indegree(n);
		vector<vector<int>> graph(n);

		for(auto &x:edges){
			graph[x[0]].push_back(x[1]);
			indegree[x[1]]++;
		}

		vector<set<int>> ancestors(n);

		queue<int> q;
		for(int node=0;node<n;node++){
			if(indegree[node] == 0){
				q.push(node);
			}
		}

		int index = 0;
		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(int &child:graph[node]){
				ancestors[child].insert(node);
				ancestors[child].insert(ancestors[node].begin(), ancestors[node].end());
				if(--indegree[child] == 0)
					q.push(child);
			}
		}

        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
        	ans[i].insert(ans[i].begin(), ancestors[i].begin(), ancestors[i].end());
        }
        return ans;
    }
};