const long long MOD = 1e9+7;
class Solution {
public:
    int waysToSplit(vector<int> &nums) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }        

        int ans = 0;
        for(int i=0;i<n-1;i++){

            // search left boundary
            auto j = lower_bound(nums.begin()+i+1, nums.end(),2*nums[i])-nums.begin();
            
            // search right boundary
            int sum = (nums[n-1]-nums[i])/2 + nums[i];
            auto k = upper_bound(nums.begin()+j+1, nums.end()-1,sum) - nums.begin();
            
            if( j >= k || j >= n || k >= n) continue;

            if( nums[j]-nums[i] <= nums[n-1]-nums[k-1])
                ans += k-j;
            ans %= MOD;
        }
        return ans;
    }
};
