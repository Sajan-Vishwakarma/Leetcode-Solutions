class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int left = 0, right = nums.size()-1;
        
        while( left <= right){
            
            int mid = (left+right)/2;
            if( nums[mid] == target) return mid;
            
            // if we are in left part
            if( nums[0] <= nums[mid] ){
                if( target > nums[mid] or target < nums[0])
                    left = mid+1;
                else 
                    right = mid-1;
            }
            else{
                if( target < nums[mid] or target > nums[n-1])
                    right = mid-1;
                else
                    left = mid+1;
            }
        }
        return -1;
    }
};