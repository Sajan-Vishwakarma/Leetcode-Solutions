class Solution {
public:
    int maximumSwap(int num) {
        
        string s = to_string(num);
        string x=s;
        
        sort(x.begin(),x.end(),greater<char>());
        
        int i;
        for( i=0;i<s.size();i++) {
            if(x[i]!=s[i])break;
        }
        
        for(int j=s.size()-1;j>=0;j--)
        {
            if(s[j]==x[i]){
                swap(s[j],s[i]);
                break;
            }
        }
        int ans=0;
        for(int i=0;i<s.size();i++) {
            ans=ans*10+s[i]-'0';
        }
        return ans;
    }
};