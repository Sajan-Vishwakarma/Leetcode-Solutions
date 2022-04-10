class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size(), hindex = 0;
        for(int i=0;i<n;i++){
            int papers = n-i;
            if( citations[i] >= papers){
                hindex = n-i;
                break;
            }
        }
        return hindex;
    }
};