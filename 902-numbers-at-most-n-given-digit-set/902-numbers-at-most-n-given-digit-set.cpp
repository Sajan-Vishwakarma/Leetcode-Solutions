class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int num) {
        
        int mask = 0;
        for(auto d:digits){
            mask |= (1<<stoi(d));
        }   
        
        string s = to_string(num);
        int n = s.size();

        vector<vector<int>> dp(10,vector<int>(2,-1));

        int start = 0;
        function<int(int,int)> fun= [&](int pos,int tight)->int{
            if( pos >= n) return 1;

            int &ans = dp[pos][tight];
            if(ans != -1) return ans;

            int maxD = (tight)?s[pos]-'0':9;
            int begD = (pos==start)?1:0;
            
            ans = 0;
            for(int d=begD;d<=maxD;d++){
                if( (mask>>d)&1 ) 
                    ans += fun(pos+1,(tight && (d==s[pos]-'0')));
            }
            return ans;
        };

        int ans = 0;
        ans += fun(0,true);
        for(int i=1;i<n;i++){
            ans += fun(i,false);
        }
        
        return ans;
    }

};