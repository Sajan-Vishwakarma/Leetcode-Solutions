class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        map<int,int> mp;
        for(int i:arr){
            mp[i%k]++;
        }
        
        for(auto &[v,cnt]:mp){
            int val = abs(v);
            int inval = abs(k-val);
            if(val == 0){
                if(cnt&1) return false;
            }
            else if(mp[val]-mp[inval]+mp[-inval]-mp[-val] != 0){
                return false;
            }
        }
        return true;
    }
};