class Solution {
public:
    string showbits(int n){
        if( n == 0) return "0";
        string bits="";
        for(int i=0;i<31;i++){
            if(n&(1<<i)) bits+='1';
            else bits += '0';
        }
        while(bits.back() == '0') bits.pop_back();
        reverse(bits.begin(), bits.end());
        return bits;
    }
     
    int findIntegers(int num) {
        
        string digit = showbits(num);
        int n = digit.size();

        int dp[35][3][2];
        memset(dp,-1,sizeof(dp));

        int start = 0;
        function<int(short,short,bool)> fun=[&](short pos,short prev,bool tight)->int{

            if( pos >= n) return 1;

            auto &ans = dp[pos][prev][tight];
            if(ans != -1) return ans;
            
            int maxD =  (tight)?digit[pos]-'0':1;
            int begD = (start==pos)?1:0;

            ans = 0;
            for(int d=begD;d<=maxD;d++){
                if( prev == 1 && d == 1) continue;
                ans += fun(pos+1,d,(tight&&(d==digit[pos]-'0')));
            }
            return ans;
        };

        int ans = fun(0,2,true);
        for(int i=1;i<n;i++){
            start = i;
            ans += fun(i,2,false);
        }

        return ans+1;
    }
};