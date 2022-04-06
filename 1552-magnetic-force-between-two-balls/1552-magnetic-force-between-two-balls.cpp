class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        
        auto CHECK=[&](int val){
            int last = 0, placed = 1;
            for(int i=1;i<position.size();i++){
                if( position[i] - position[last] >= val ){
                    last = i;
                    placed++;
                }
            }
            if( placed < m) return false;
            return true;
        };
        
        int low = 1, high = 1e9+100, gap = 0;
        while(low <= high){
            int mid = (low+high)/2;
            if(CHECK(mid)){
                gap = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return gap;
    }
};