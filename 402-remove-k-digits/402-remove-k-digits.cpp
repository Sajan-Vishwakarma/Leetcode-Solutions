class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        
        string s="";
        for(int i=0;i<n;i++){
            char ch = num[i];
            if(!s.empty()){
                while(!s.empty() && s.back() > ch && k){
                    s.pop_back();
                    k--;
                }
            }    
            if(ch == '0' && s.empty())
                continue;
            s.push_back(ch);
        }
        while(!s.empty() && k--) s.pop_back();
        if(s.empty()) return "0";
        return s;
    }
};