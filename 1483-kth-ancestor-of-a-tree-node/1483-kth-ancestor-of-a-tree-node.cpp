class TreeAncestor {
public:
    
    int max_log, N;
    vector<vector<int>> dp;
    
    TreeAncestor(int n, vector<int>& parent) {
        
        N = n;
        max_log = log2(n) + 1;
        dp.resize(max_log);
        
        dp[0].resize(n+1,n);
        for(int i=0;i<n;i++){
            dp[0][i] = parent[i];
        }
        dp[0][0] = n;
        
        for(int j=1;j<max_log;j++){
            dp[j].resize(n+1,n);
            for(int i=0;i<n;i++){
                dp[j][i] = dp[j-1][dp[j-1][i]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int par = node;
        for(int bit=max_log; bit>=0 && k; bit--){
            if( k&(1<<bit)){
                par = dp[bit][par];
            }
        }
        if(par != N) return par;
        return -1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */