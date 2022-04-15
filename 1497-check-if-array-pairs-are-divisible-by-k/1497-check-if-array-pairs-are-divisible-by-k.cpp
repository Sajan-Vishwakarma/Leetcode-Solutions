class Solution {
public:
    bool canArrange(vector<int>& v, int k) {
        
        map<int,int> mp;
        for(int i:v){
            mp[((i%k)+k)%k]++;
        }
        
        if( mp[0]&1 ){
            return false;
        }

        for(auto &[val,cnt]:mp){
            if(val == 0) continue;
            
            int pairval = abs(k-val);
            if( mp[val] != mp[pairval]){
                return false;
            }
        }
        return true;
    }
};