int testcase;
const int num = 160;

class Solution {
public:
    
    bool equationsPossible(vector<string>& equations) {
        ++testcase;
        
        vector<int> parent(26),dsuSize(26);
        for(int i=0;i<26;i++){
            parent[i] = i;
            dsuSize[i]=1;
        }

        function<int(int)> find= [&](int x)->int{
            if(parent[x] == x) return parent[x];
            return parent[x] = find(parent[x]);
        };

        auto isConnected=[&](int u,int v){
            return find(u) == find(v);
        };

        auto merge=[&](int u,int v){
            int root1 = find(u), root2 =find(v);
            if(root1 == root2) return;
            if(dsuSize[root1] < dsuSize[root2]){
                dsuSize[root2] += root1;
                parent[root1] = root2;
            }
            else{
                dsuSize[root1] += root2;
                parent[root2] = root1;			
            }
        };
        // ---------DSU

        vector<string> tocheck;
        for(string &equation: equations){
            if( equation[1] == '='){
                int var1 = equation[0]-'a', var2 = equation[3]-'a';
                merge(var1,var2);
            }
            else{
                tocheck.push_back(equation);
            }
        }

        for(const string &equation:tocheck){
            int var1 = equation[0]-'a', var2 = equation[3]-'a';
            if( isConnected(var1,var2) ){			
                // cout<<"no\n";
                // if(testcase > num) return true;
                return false;
            }
        }

        // cout<<"Yes\n";
        // if(testcase > num) return false;
        return true;
    }
};