const long long MOD = 1e9+7;
class Solution {
public:
    int binarySearch(vector<int> &nums) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }        

        int ans = 0;
        for(int i=0;i<n;i++){

            int sum = (nums[n-1]-nums[i])/2 + nums[i];
            auto j = lower_bound(nums.begin()+i+1, nums.end(),2*nums[i])-nums.begin();
            auto k = upper_bound(nums.begin()+j+1, nums.end()-1,sum) - nums.begin();
            
            if( j >= n || k >= n) continue;
            if( nums[j]-nums[i] <= nums[n-1]-nums[k-1])
                ans += k-j;
            ans %= MOD;
        }
        return ans;
    }
    
    int waysToSplit(vector<int> &nums) {
        // return binarySearch(nums);
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }    

        int res = 0;
        for(int i=0,j=0,k=0; i<n; i++){
            j = max(i+1,j);
            while( j < n-1 && nums[j] < 2*nums[i])
                j++;

            k = max(j,k);
            while( (k < n-1) && (nums[k]-nums[i] <= nums[n-1]-nums[k]))
                k++;
            res += k-j;
            res %= MOD;
        }    
        return res;
    }
};
