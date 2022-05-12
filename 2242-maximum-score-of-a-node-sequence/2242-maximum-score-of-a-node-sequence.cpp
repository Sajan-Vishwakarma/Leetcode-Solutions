class Solution {
public:
    int maximumScore(vector<int> &scores,vector<vector<int>> &edges) {
        int n = scores.size();

        vector<vector<pair<int,int>>> graph(n);
        
        for(vector<int> &edge:edges){
            int u = edge[0], v=edge[1];
            graph[u].push_back({scores[v],v});
            graph[v].push_back({scores[u],u});
            
            sort(graph[u].rbegin(),graph[u].rend());
            sort(graph[v].rbegin(),graph[v].rend());

            if(graph[u].size() > 3) 
                graph[u].pop_back();
            if(graph[v].size() > 3) 
                graph[v].pop_back();
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