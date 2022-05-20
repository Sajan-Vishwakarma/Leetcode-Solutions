class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
            
        int n = parent.size();
        vector<vector<int>> tree(n);

        for(int u=1;u<n;u++){
            int v = parent[u];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        int ans =0;
        vector<bool> visited(n,false);
        
        function<int(int,int)> dfs= [&](int node,int par)->int{
            
            visited[node] = true;            
            vector<int> temp;
            for(auto &child:tree[node]){
                if(child == par || s[child] == s[node])
                    continue;
                temp.push_back(dfs(child,node));
            }

            int fmx = 0, smx = 0;
            for(int &i:temp){
                if( i >= fmx){
                    smx = fmx;
                    fmx = i;
                }
                else if(i >= smx){
                    smx = i;
                }
            }

            // dbg(node,temp,fmx,smx,"\n");

            ans = max(ans,fmx+smx+1);
            return 1 + fmx;
        };

        for(int node=0;node<n;node++){
            if(!visited[node])
                ans = max(ans, dfs(node,parent[node]));
        }
        return ans;
    }
};