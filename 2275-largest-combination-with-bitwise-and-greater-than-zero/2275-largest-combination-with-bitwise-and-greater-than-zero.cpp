class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        vector<int> count(31,0);
        for(int num:candidates){
            for(int bit=30;bit>=0;bit--){
                count[bit] += ((num>>bit)&1);
            }
        }
        
        return *max_element(count.begin(),count.end());
    }
};