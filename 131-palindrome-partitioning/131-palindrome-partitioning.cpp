using vvs =  vector<vector<string>>;
using vvb = vector<vector<bool>>;
class Solution {
public:
    
    
    void fun(int pos,string &s,vector<string> &temp,vvs &ans,vvb &isPal){
        if(pos == s.size()){
            ans.push_back(temp);
            return;
        }
        
        string str="";
        for(int i=pos;i<s.size();i++){
            str  += s[i];
            
            if( isPal[pos][i] ){
                temp.push_back(str);
                fun(i+1,s,temp,ans,isPal);
                temp.pop_back();
            }
        }         
    }
    
    vector<vector<string>> partition(string s) {
        
        int n = s.size();
        vector<vector<bool>> isPal(n+1,vector<bool>(n+1,false));
        for(int i=0 ;i<n;i++){
            isPal[i][i] = true;
            if(i>0) isPal[i-1][i] = (s[i-1]==s[i]);
        }
        
        for(int len=3;len<=s.size();len++){
            for(int i=0;i<n;i++){
                int j = i+len-1;
                if(j >= n) break;
                isPal[i][j] = isPal[i+1][j-1] && (s[i] == s[j]);
            }
        }
//         aab
//         TT*
//         *T*
//         **T
        
        vector<vector<string>> ans;
        vector<string> temp;
        fun(0,s,temp,ans,isPal);
        return ans;
    }
};