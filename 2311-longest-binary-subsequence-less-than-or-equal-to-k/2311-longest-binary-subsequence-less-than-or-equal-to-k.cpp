
class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        int n=s.size();
        vector<int> pref(n,0);
        
        for(int i=0;i<n;i++){
            pref[i] += (s[i]=='0');
            if(i) pref[i] += pref[i-1];
        }

        long long bit=0, num = 0;
        for(int i=n-1;i>=0;i--){

            if(s[i] == '1'){
                if(bit > 34) continue;
                if( num+(1LL<<bit) > k){
                    return bit+pref[i];
                }
                else{
                    num += (1LL<<bit);
                    bit++;
                }
            }
            else{
                bit++;
            }
        }

        return bit;
    }
};