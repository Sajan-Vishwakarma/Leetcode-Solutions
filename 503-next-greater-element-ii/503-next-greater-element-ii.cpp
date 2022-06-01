class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> stk;
        int n = nums.size();
        
        for(int i=n-1;i>=0;i--){
            stk.push(nums[i]);
        }
        
        vector<int> ans(n);
        
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && nums[i] >= stk.top()){
                stk.pop();
            }
            
            ans[i] = (stk.empty())?-1:stk.top();
            stk.push(nums[i]);
        }
        return ans;
    }
};