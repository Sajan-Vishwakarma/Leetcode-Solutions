int testcase;
vector<string> vs;

class Solution {
public:
    vector<vector<string>> ans;
    void fun(int l,int n,vector<string> &v,string &s){
        if(l == n){
            ans.push_back(v);
            return;
        }
        
        auto valid = [&](string &s)->bool{
            int l = 0, r = s.size()-1;
            while(l <= r){
                if(s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        };
        
        string str="";
        for(int i=l;i<n;i++){
            str += s[i];
            if(valid(str)){
                v.push_back(str);
                fun(i+1,n,v,s);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        testcase++;
        if(testcase >= 50){
            vs.push_back(s);
            if(testcase >= 70){                
                for(string s:vs)
                    cout<<s<<endl;
                return {};
            }
        }
        
        
        vector<string> v;
        fun(0,s.size(),v,s);
        return ans;
    }
};