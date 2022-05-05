class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        
        vector<string> tocheck;
        map<char, vector<char>> graph;
        
        for(string &equation: equations){
            // separate equal and notequal equation
            if( equation[1] == '='){
                char var1 = equation[0], var2 = equation[3];
                graph[var1].push_back(var2);
                graph[var2].push_back(var1);
            }
            else{
                tocheck.push_back(equation);
            }
        }


        function<void(char,set<char>&)> dfs= [&](char node,set<char> &visited)->void{

            visited.insert(node);
            for(char ch:graph[node]){
                if(!visited.count(ch)){
                    visited.insert(ch);
                    dfs(ch,visited);
                }
            }
        };

        for(const string &equation:tocheck){
            set<char> visited;
            char var1 = equation[0], var2 = equation[3];
            visited.insert(var1);
            dfs(var1,visited);
            // connected together var1 and var2, that's var1 was able to visit var2
            if(visited.count(var2)){			
                // cout<<"no\n";
                return false;
            }
        }

        // cout<<"Yes\n";
        return true;
    }
};