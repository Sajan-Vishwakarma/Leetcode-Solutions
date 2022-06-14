class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        
        vector<vector<int>> dp(n+10,vector<int>(m+10,-1));
        
        function<bool(int,int,vector<vector<int>>&)> suffixMatch=[&](int i,int j,vector<vector<int>> &dp)->bool{           
            if( i == n && j == m) return true;
            if( j == m ) return false;
            if( i == n ){
                for(int k=j; k < m; k+=2){
                    if( k+1 >= m || p[k+1] != '*'){
                        return false;
                    }
                }
                return true;
            }        
            
            int &ans = dp[i][j];
            if(ans != -1) return ans;
            
            if( j+1 < m && p[j+1] == '*'){ 
                int k = 0;
                while(true){
                    if( suffixMatch(i+k,j+2,dp) ) return ans = true;
                    if(i+k >= n) break;
                    if( p[j] != '.' && s[i+k] != p[j] ) break;
                    k++;
                }
                return ans = false;
            }
            
            if( s[i] == p[j] || p[j] == '.')
                return ans = suffixMatch(i+1,j+1,dp);
            
            return ans = false;    
        };
        
        return suffixMatch(0,0,dp);
    }
};