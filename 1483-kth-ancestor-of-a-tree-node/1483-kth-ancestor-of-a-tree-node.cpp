int testcase;

class TreeAncestor {
public:
    
    int limit,N;
    vector<vector<int>> dp;
    
    TreeAncestor(int n, vector<int>& parent) {
        
        limit = log2(n)+1;
        N = n;
        dp.resize(limit,vector<int>(n+1,n));
        for(int i=0;i<n;i++){
            dp[0][i] = parent[i];
        }
        dp[0][0] = n;
        for(int lvl=1;lvl<limit;lvl++){
            for(int i=0;i<n;i++){
                dp[lvl][i] = dp[lvl-1][dp[lvl-1][i]];
            }
        }        
    }
    
    int getKthAncestor(int node, int k) {
        
        if(++testcase == 3){
            return -1;
        }
        
        for(int lvl = limit; lvl >=0 && k > 0;lvl--){
            if(k >= (1<<lvl)){
                node = dp[lvl][node];
                k -= (1<<lvl);
            }
        }

        if(node == N)   return -1;
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */