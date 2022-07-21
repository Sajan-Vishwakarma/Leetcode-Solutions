class Solution {
public:
    int countBinarySubstrings(string s) {

        int n = s.size();
        int ans = 0, prev = 0; 
        
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            int j = i, cnt = 0;
            for(; j<n;j++){
                if(s[i] == s[j])
                    cnt++;
                else
                    break;
            }
            i = j-1;
            ans += min(prev,cnt);
            prev = cnt;
        }
        
        return ans;
    }
};