class Solution {
public:
    map<pair<int,int>, pair<int,int>> dp;
    pair<int,int> solve(int st, int en, vector<int> &a) {
        if(st == en) {
            return {a[st], 0}; // maxleaf, minSum
        }
        if(dp.count({st,en})) return dp[{st,en}];
        int maxLeaf = INT_MIN, minSum = INT_MAX;
        for(int j = st; j < en; j++) {
            auto left = solve(st,j,a);
            auto right = solve(j+1,en,a);
            maxLeaf = max(left.first, right.first);
            minSum = min(minSum, left.first * right.first + left.second + right.second);
        }
        return dp[{st,en}] = {maxLeaf, minSum};
    }
    
    int mctFromLeafValues(vector<int>& a) {
        // memset(dp,-1,sizeof(dp));
        int n = a.size();
        return solve(0,n-1,a).second;
    }
};