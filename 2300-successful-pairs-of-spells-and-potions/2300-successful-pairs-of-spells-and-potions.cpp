class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& portions, long long success) {
        
        sort(portions.begin(),portions.end());
        
        vector<int> ans;
        for(int s:spells){
            long f = success/s + (success%s !=0 );
            ans.push_back( portions.end() - lower_bound(portions.begin(),portions.end(),f));
        }
        return ans;
    }
};