class Solution {
public:
    int maximumScore(vector<int> &scores,vector<vector<int>> &edges) {
        int n = scores.size();

        vector<set<pair<int,int>>> graph(n);
        
        for(vector<int> &edge:edges){
            int u = edge[0], v=edge[1];
            graph[u].insert({scores[v],v});
            graph[v].insert({scores[u],u});

            if(graph[u].size() > 3) 
                graph[u].erase(graph[u].begin());
            if(graph[v].size() > 3) 
                graph[v].erase(graph[v].begin());
        }

        int ans= -1;
        for(vector<int> edge:edges){
            int b = edge[0], c = edge[1];

            for(auto &[wta,a]:graph[b]){
                if(a == c) continue;
                for(auto &[wtd,d]: graph[c]){
                    if(d == a || d == b) continue;
                    ans = max(ans, wta+scores[b]+scores[c]+wtd);
                }
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
};