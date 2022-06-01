class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> stk;
        unordered_map<int,int> mp;
        
        int n = nums2.size();
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && nums2[i] > stk.top()){
                stk.pop();
            }
            
            mp[nums2[i]] = (stk.empty())?-1:stk.top();
            stk.push(nums2[i]);
        }
        
        vector<int> ans;
        for(int i:nums1){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};