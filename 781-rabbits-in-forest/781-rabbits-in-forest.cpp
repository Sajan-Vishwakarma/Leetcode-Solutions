class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int &i:answers){
            mp[i]++;
        }
        
        int ans = 0;
        for(auto &[r,cnt]:mp){
            ans += (((r+cnt)/(r+1))*(r+1));
        }
        return ans;
    }
};