#define MOD 1000000007
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        set<int> st(nums1.begin(),nums1.end());
        
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += abs(nums1[i] - nums2[i]);
        }
        
        long long ans = sum;
        for(int i=0;i<n;i++){
            auto it = st.lower_bound(nums2[i]);    
            if( it != st.begin() ){
                ans = min(ans, sum - abs(nums1[i]-nums2[i]) + abs(*prev(it)-nums2[i]));
            }
            if( it != st.end() ){
                ans = min(ans, sum - abs(nums1[i]-nums2[i]) + abs(*it-nums2[i]));
            }
        }
        
        return int(ans%MOD);
    }
};