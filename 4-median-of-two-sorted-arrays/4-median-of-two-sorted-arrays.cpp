class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        
        int median = (nums1.size() + nums2.size())/2;
        
        int i = 0;
        int j = 0;
        
        double result;
        
        if(nums1.size() == 0){
            if(nums2.size() % 2 == 0){
                result = (double)(nums2[nums2.size()/2 - 1] + nums2[nums2.size()/2])/2;
            }
            else{
                result = nums2[nums2.size()/2];
            }
            return result;
        }
        else if(nums2.size() == 0){
            if(nums1.size() % 2 == 0){
                result = (double)(nums1[nums1.size()/2 - 1] + nums1[nums1.size()/2])/2;
            }
            else{
                result = nums1[nums1.size()/2];
            }
            return result;
        }
        while(nums.size() < median + 1){
            if(i > nums1.size() - 1){
                nums.push_back(nums2[j]);
                j++;
            }
            
            else if(j > nums2.size() - 1){
                nums.push_back(nums1[i]);
                i++;
            }
            
            else{
                if(nums1[i] < nums2[j]){
                    nums.push_back(nums1[i]);
                    i++;
                }
                else{
                    nums.push_back(nums2[j]);
                    j++;
                }
            }
        }  
        
        if((nums1.size() + nums2.size()) % 2 == 0){
            result = (double)(nums[median - 1] + nums[median])/2;
        }
        
        else{
            result = nums[median];
        }
        
        return result;
    }
};