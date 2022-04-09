class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        if( bloomDay.size() < m*k) return -1;
        
        auto CHECK=[&](int day){
            
            int count = 0, len=0;
            for(int i=0;i<bloomDay.size();i++){
                if( bloomDay[i] > day){
                    len = 0;
                    continue;
                }
                len++;
                if( len >= k){
                    count++;
                    len = 0;
                }
            }
            
            return count >= m;
        };
        
        int low = 1, high = 1e9+10, ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if( CHECK(mid) ){
                ans=mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};