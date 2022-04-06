class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        auto CHECK=[&](int val){
            int time = 0;
            for(int i:piles){
                time += (i+val-1)/val;
            }
            return time <= h;
        };
        
        int low = 1, high = 1e9+100, ans = 0;
        while(low <= high){
            int mid = (low+high)/2;
            if(CHECK(mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};