class Solution {
public:
    int numDupDigitsAtMostN(int num) {
        
        string s = to_string(num);
        int n = s.size();

        int dp[10][1025][2][2];
        memset(dp,-1,sizeof(dp));

        int start = 0;
        function<int(int,int,int,int)> fun= [&](int pos,int mask,int rep,bool tight)->int{

            if( pos >= n){
                return (rep)?1:0;
            }

            int &ans = dp[pos][mask][rep][tight];
            if( ans != -1) return ans;

            int maxD = (tight)?s[pos]-'0':9;
            int begD = (start==pos)?1:0;

            ans = 0;
            for(int d=begD; d <= maxD; d++){
                ans += fun(pos+1,mask|(1<<d),(mask&(1<<d)||rep), (tight && d==(s[pos]-'0')) );
            }
            return ans;
        };

        int ans = fun(0,0,false,true);
        for(int i=1;i<n;i++){
            start = i;
            ans += fun(i,0,false,false);
        }

        return ans;
    }

};