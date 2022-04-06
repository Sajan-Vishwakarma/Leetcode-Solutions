#define MOD 1000000007
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        int ans = 0;
        for(int i=0;i<n;i++){
            
            int t = target - arr[i];
            int j = i+1, k = n-1;
            while(j < k){
                
                if( arr[j] + arr[k] < t){
                    j++;
                }
                else if( arr[j] + arr[k] > t){
                    k--;
                }
                else if( arr[j] != arr[k]){
                    int left = 1, right = 1;
                    while( j+1 < k && arr[j] == arr[j+1]) {
                        left++;
                        j++;
                    }
                    while( k-1 > j && arr[k] == arr[k-1]){
                        right++;
                        k--;
                    }
                    
                    ans += left*right;
                    ans %= MOD;
                    j++;
                    k--;
                }
                else{
                    ans += (k-j+1)*(k-j)/2;
                    ans %= MOD;
                    break;
                }
            }
        }
        
        return ans;
    }
};