class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int num) {
        
        int mask = 0;
        for(auto &d:digits){
            mask |= (1<<stoi(d));
        }   
        
        string s = to_string(num);
        int n = s.size();

        int dp[11][2];
        memset(dp,-1,sizeof(dp));

        int start = 0;
        function<int(short,bool)> fun= [&](short pos,bool tight)->int{
            if( pos >= n) return 1;

            if( dp[pos][tight] != -1) return dp[pos][tight];

            int maxD = (tight)?s[pos]-'0':9;
            int begD = (pos==start)?1:0;
            
            int ans = 0;
            for(int d=begD;d<=maxD;d++){
                if( (mask>>d)&1 ) 
                    ans += fun(pos+1,(tight && (d==s[pos]-'0')));
            }
            return dp[pos][tight] = ans;
        };

        int ans = 0;
        ans += fun(0,true);
        for(int i=1;i<n;i++){
            start = i;
            ans += fun(i,false);
        }
        
        return ans;
    }

};