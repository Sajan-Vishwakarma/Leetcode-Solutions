class Solution {
public:
    void pp(int n, int l, int r, int i,string &s,vector<string>& ans){

        if(l+r==2*n){
            ans.push_back(s);
            return;
        }
        
        if(l==r){
            s[i]='(';
            pp(n,l+1,r,i+1,s,ans);
        }
        else if(l>r)
        {
            if(l==n){
                s[i]=')';
                pp(n,l,r+1,i+1,s,ans);
            }else{
                s[i]='(';
                pp(n,l+1,r,i+1,s,ans);
                
                s[i]=')';
                pp(n,l,r+1,i+1,s,ans);
            }
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s(2*n,'*');        
        
        pp(n,0,0,0,s,ans);
        return ans;
    }
};