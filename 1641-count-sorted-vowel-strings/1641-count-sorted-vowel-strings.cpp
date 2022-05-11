class Solution {
public:
    

    int countVowelStrings(int n) {
        
        vector<int> dp{1,1,1,1,1};
 
        for(int i=1;i<n;i++){
            vector<int> newdp(5,0);
            for(int ch=0;ch<5;ch++){
                for(int newch=ch;newch<5;newch++)
                    newdp[ch] += dp[newch];    
            }
            swap(dp,newdp);
        }
        
        return accumulate(dp.begin(),dp.end(),0);
    }
};