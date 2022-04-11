class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        auto CHECK=[&](int index){
            if((index+1)&1){
                return nums[index] == nums[index+1];
            }
            return nums[index] == nums[index-1];
        };
            
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(CHECK(mid)){
                low = mid+1;    
            }
            else{
                high = mid-1;
            }
        }
        return nums[low];
    }
};