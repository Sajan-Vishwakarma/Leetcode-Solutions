const long long MOD = 1e9+7;
class Solution {
public:
    int waysToSplit(vector<int> &nums) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }        

        int ans = 0;
        for(int i=0;i<n-2;i++){
            // search right boundary
            auto CHECK = [&](int mid)->int{
                return nums[mid]-nums[i] <= nums[n-1]-nums[mid];
            };
            
            int low = i+1, high = n-2, k = 0;
            while(low <= high){
                int mid = (low + high)/2; 
                if( CHECK(mid) ){
                    k = mid;
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            
            // search left boundary
            auto j = lower_bound(nums.begin()+i+1, nums.end(),2*nums[i])-nums.begin();
            if( j > k) continue;
            ans += k-j+1;
            ans %= MOD;
        }
        return ans;
    }
};
