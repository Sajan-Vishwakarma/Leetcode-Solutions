class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        int n = chalk.size();
        
        vector<long long> chalks(n);
        for(int i=0;i<n;i++){
            chalks[i] = chalk[i];
            if(i) chalks[i] += chalks[i-1];
        }
        k %= chalks[n-1];
        
        auto CHECK=[&](int idx){
            return chalks[idx] <= k;
        };
        
        int low = 0, high = n-1, ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(CHECK(mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return (ans+1)%n;
    }
};