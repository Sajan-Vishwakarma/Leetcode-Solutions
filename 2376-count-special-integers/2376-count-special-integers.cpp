class Solution {
public:
    int countSpecialNumbers(int num){
        string s = to_string(num);
        int n = s.size();

        int dp[n][1025][2];
        memset(dp,-1,sizeof(dp));
        
        int start = 0;
        function<int(short,short,short)> fun=[&](short pos,short mask,bool tight)->int{
            
            if( pos >= n) return 1;

            if( dp[pos][mask][tight] != -1) 
                return dp[pos][mask][tight];
            
            // if(pos == start i.e we are starting number here so it can't be 0)
            // handle leading zero.
            
            int begD = (pos==start)?1:0; 
            int maxD = (tight)?s[pos]-'0':9;
            
            int ans = 0;
            for(int d=begD ; d <= maxD ; d++){
                if( mask&(1<<d) ) continue;
                ans += fun(pos+1,mask|(1<<d), (tight && d==(s[pos]-'0')));
            }
            
            return dp[pos][mask][tight] = ans;
        };

        int ans = fun(0,0,true);
        for(int i=1;i<n;i++){ 
            // to handle leading zeroes for number of length less n;
            start = i;
            ans += fun(i,0,false);
        }

        return ans;
    }
};