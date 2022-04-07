class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        auto CHECK=[&](int divisor){
            int sum = 0;
            for(int i:nums){
                sum += (i+divisor-1)/divisor;
            }  
            return sum <= threshold;
        };
        
        int low = 1, high = 1e9+10, ans = 0;
        while(low <= high ){
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