class Solution {
public:
    
    const int mod = 1e9+7;
    
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> left(n,-1), right(n,-1);
        
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && (arr[stk.top()] > arr[i])){
                stk.pop();
            }
            left[i] = (stk.empty())?-1:stk.top();
            stk.push(i);
        }
        stk = {};
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && (arr[stk.top()] >= arr[i])){
                stk.pop();
            }
            right[i] = (stk.empty())?n:stk.top();
            stk.push(i);
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            int l = i-left[i], r = right[i]-i;
            ans += (((l*1LL*r)%mod)*(arr[i]%mod))%mod;
            if( ans > mod) ans -= mod;
        }
        return ans;
    }
};