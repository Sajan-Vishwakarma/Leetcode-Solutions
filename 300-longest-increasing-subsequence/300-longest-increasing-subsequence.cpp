class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for(int i=0;i<nums.size();i++){
            auto it = lower_bound(lis.begin(),lis.end(),nums[i]);
            if( it == lis.end()){
                lis.push_back(nums[i]);
            }
            else{
                int index = it - lis.begin();
                lis[index] = nums[i];
            }
        }
        
        return int(lis.size());
    }
};