class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == key && i+1 < nums.size())
                mp[nums[i+1]]++;
        }
        
        int ans = 0, mx = 0;
        for(auto &[x,cnt]:mp){
            if(cnt > mx){
                mx = cnt;
                ans = x;
            }
        }
        
        return ans;
    }
};