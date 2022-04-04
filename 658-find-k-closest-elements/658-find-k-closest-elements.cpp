class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int low = 0, high = arr.size()-k;
        while( low < high){
            int mid = (low+high)/2;
            if(  x-arr[mid] <= arr[mid+k]-x ){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        
        return vector<int>(arr.begin()+low, arr.begin()+low+k); 
    }
};