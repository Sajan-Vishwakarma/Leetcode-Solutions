class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        const int inf = 1e9;
        int idx = (lower_bound(arr.begin(),arr.end(),x)) - arr.begin();
        
        int i = idx-1, j = idx;
        while(k--){
            int diff1 = inf, diff2 = inf;
            if( i >= 0) diff1 = abs(arr[i] - x);
            if( j < arr.size()) diff2 = abs(arr[j] - x);
            
            if( diff1 <= diff2){
                i--;
            }
            else{
                j++;
            }
        }
        
        vector<int> res;
        for(int it=i+1;it<j;it++) res.push_back(arr[it]);
        return res;
    }
};