class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        
        vector<int> v;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            int j = i, cnt = 0;
            for(; j<n;j++){
                if(s[i] == s[j])
                    cnt++;
                else
                    break;
            }
            v.push_back(cnt);
            i = j-1;
        }
        
        int ans = 0;
        for(int i=1;i<v.size();i++){
            ans += min(v[i-1],v[i]);
        }
        
        return ans;
    }
};