class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        auto CHECK=[&](int val){
            int moves = 0;
            for(int &b:nums){
                if( b <= val) continue;
                moves += (b/val) - (b%val == 0);
            }
            return moves <= maxOperations;
        };
        
        int low = 1, high = 1e9+10, ans = -1;
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