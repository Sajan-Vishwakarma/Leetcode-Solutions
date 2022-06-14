using vvb = vector<vector<bool>>;

class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n = s.size(), m = p.size();

        vector<vector<bool>> dp(n+1,vector<bool>(m+1,NULL));

        function<bool(int,int,vvb&)> fun= [&](int i,int j,vvb &dp)->bool{

            if(i == n && j == m) return true;
            if(i>n || j >= m) return false;

            if(i == n){
                // checking remaining pattern
                for(int k=j; k < m; k+=2){
                    if( k+1 >= m || p[k+1] != '*'){
                        return false;
                    }
                }
                return true;
            }

            if(dp[i][j] != NULL)
                return dp[i][j];

            bool ans = false;
            if(s[i] == p[j] || p[j] == '.' ){
                ans |= fun(i+1,j+1,dp);
            }

            if(j+1<m && p[j+1] == '*'){
                
                ans |= fun(i,j+2,dp); // matching 0 characters
                
                // 1 or more characters of same p[j] match
                for(int match=0; (i+match < n) && (p[j]==s[i+match]); match++){ 
                    ans |= fun(i+match+1,j+2,dp);  
                    if(ans) return dp[i][j] = ans;
                }

                // matching more than 1 characters i.e '.*'
                if(p[j] == '.'){
                    for(int match=1;match<=n;match++){
                        ans |= fun(i+match,j+2,dp);
                        if(ans) return dp[i][j] = ans;
                    } 
                }
            }
            return dp[i][j] = ans;
        };

        return fun(0,0,dp);
    }
};