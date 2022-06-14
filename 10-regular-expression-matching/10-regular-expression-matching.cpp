class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n = s.size(), m = p.size();

        vector<vector<bool>> dp(n+1,vector<bool>(m+1,NULL));

        function<bool(int,int)> fun= [&](int i,int j)->bool{
            

            if(i == n && j == m) return true;
            if(i>n || j >= m) return false;

            if(i == n){
                int rem = m-j;
                for(int jj=j+1;jj<m;jj+=2){
                    if( p[jj] != '*')
                        return false;
                }
                return (rem&1)?false:true;
            }

            if(dp[i][j] != NULL)
                return dp[i][j];

            bool ans = false;

            if(s[i] == p[j] || p[j] == '.' ){
                ans |= fun(i+1,j+1);
            }

            if(j+1<m && p[j+1] == '*'){
                // matching 0 or more occurence of single character i.e s[i]*
                ans |= fun(i,j+2); // matching 0 characters

                // 1 or more characters of same p[j] match
                for(int match=0; (i+match < n) && (p[j]==s[i+match]); match++){ 
                    // dbg(i,match,i+match,s[i+match],p[j]);
                    ans |= fun(i+match+1,j+2);               
                }

                // matching more than 1 characters i.e '.*'
                if(p[j] == '.'){
                    for(int match=1;match<=n;match++){
                        // dbg(i,match,i+match);
                        ans |= fun(i+match,j+2);
                    } 
                }
            }

            return dp[i][j] = ans;
        };

        return fun(0,0);
    }
};