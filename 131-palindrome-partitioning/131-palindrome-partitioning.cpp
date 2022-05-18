class Solution {
public:
    
    bool palindrome(string s){
        int l=0,r=s.size()-1;
        while(l <= r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    void fun(int pos,string &s,vector<string> &temp,vector<vector<string>> &ans){
        if(pos == s.size()){
            ans.push_back(temp);
            return;
        }
        
        string str="";
        for(int i=pos;i<s.size();i++){
            str  += s[i];
            
            if( palindrome(str) ){
                temp.push_back(str);
                fun(i+1,s,temp,ans);
                temp.pop_back();
            }
        }         
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        fun(0,s,temp,ans);
        return ans;
    }
};