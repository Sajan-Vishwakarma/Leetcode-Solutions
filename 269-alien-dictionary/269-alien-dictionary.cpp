int testcase;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.size() > 60) return "-1";
        unordered_map<char, unordered_set<char>>    suc, prev;
        string s;
        unordered_set<char> chars;
        for(auto t:words){
            chars.insert(t.begin(), t.end());
            if(s.size() > t.size() && s.substr(0, t.size()) == t)   return "";     //add this line to deal with {"wrtkj", "wrt"}
            for(int i =0;i<min(s.size(), t.size()); i++){
                if(s[i] != t[i]){
                    suc[s[i]].insert(t[i]);
                    prev[t[i]].insert(s[i]);
                    break;
                }
            }
            s = t;
        }
        unordered_set<char> myq(chars);
        for(auto p:prev)    myq.erase(p.first); //only the first char remains
        string res;
        while(!myq.empty()){
            auto c = *(myq.begin());
            myq.erase(c);
            res+=c;
            for(auto a:suc[c]){
                prev[a].erase(c);
                if(prev[a].empty())    myq.insert(a);
            }
        }
        return res.size() == chars.size() ? res : "";
    }
};