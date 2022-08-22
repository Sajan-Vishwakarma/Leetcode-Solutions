#define vvs vector<vector<string>>

class Solution {
public:
    vector<double> calcEquation(vvs &equations, vector<double>& values, vvs& queries) {
        
        map<string,vector<pair<string,double>>> graph;
        
        for(int i=0; i < equations.size(); i++ ){
            string u = equations[i][0], v = equations[i][1];
            double cost = values[i];
            
            graph[u].push_back({v,cost});
            graph[v].push_back({u,(1.0/cost)});
        }
        
        double ans = -1.0;
        set<string> vis;
        function<void(string,string&,double)> dfs=[&](string node,string &dest,double cost){
            if( node == dest){
                ans = cost;
                return;
            }
            vis.insert(node);
            for(auto &x:graph[node]){
                string child = x.first;
                double c = x.second;
                if( vis.count(child) ) continue;
                dfs(child,dest,cost*c);
            }
        };
        
        vector<double> res;
        for(auto &query:queries){
            string u = query[0], v = query[1];
            
            if( graph.find(u)==graph.end() || graph.find(v)==graph.end() ){
                res.push_back(-1.0);
                continue;
            }
            
            ans = -1.0; 
            vis.clear();
            dfs(u,v,1.0);
            res.push_back(ans);
        }
        return res;
    }
};