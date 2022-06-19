class Solution {
public:
    long long sellingWood(int n, int m, vector<vector<int>>& prices) {
        
        vector<vector<int>> money(n+1,vector<int>(m+1));
        for(auto &x:prices){
            money[x[0]][x[1]] = x[2];
        }
        
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));

        function<long long(int,int)> maxprice= [&](int H,int W)->long long{

            auto &ans = dp[H][W];
            if(ans != -1) return ans;
            ans = money[H][W];

            for(int h=1;h <= H/2; h++){
                ans = max(ans, maxprice(h,W) + maxprice(H-h,W) );
            }

            for(int c=1;c<=W/2;c++){
                ans = max(ans, maxprice(H,c) + maxprice(H,W-c) );
            }
            return ans;
        };

        return maxprice(n,m);
    }
};