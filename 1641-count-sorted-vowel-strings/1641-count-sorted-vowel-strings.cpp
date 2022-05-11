class Solution {
public:
    

    int countVowelStrings(int n) {
        
        map<char,vector<char>> mp;  
        mp['a'] = {'a','e','i','o','u'};
        mp['e'] = {'e','i','o','u'};
        mp['i'] = {'i','o','u'};
        mp['o'] = {'o','u'};
        mp['u'] = {'u'};

        
        function<int(char,int)> fun=[&](char ch,int len)->int{    
            if(len == n) return 1;
        
            int ans = 0;
            for(char nextch:mp[ch]){
                ans += fun(nextch,len+1);
            }
            return ans;
        };
        
        int ans = 0;
        for(char ch='a';ch<='z';ch++){
            if(mp.find(ch) == mp.end()) continue;
            ans += fun(ch,1);
        }
        return ans;
    }
};