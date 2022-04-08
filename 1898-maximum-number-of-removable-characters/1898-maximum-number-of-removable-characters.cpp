class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        auto CHECK=[&](string s,const string &p,int index){
            
            for(int i=0;i<=index;i++){
                s[removable[i]] = '?';
            }
            
            int i =0 , j = 0;
            while( i < s.size() && j < p.size()){
                if( s[i] == '?' ){
                    i++;
                    continue;    
                } 
                
                if( s[i] == p[j] ){
                    j++;
                }
                i++;
            }
            return j == p.size();
        };
        
        int low = 0, high = removable.size()-1, ans = -1;
        while( low <= high ){
            int mid = (low+high)/2;
            if(CHECK(s,p,mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans+1;
    }
};