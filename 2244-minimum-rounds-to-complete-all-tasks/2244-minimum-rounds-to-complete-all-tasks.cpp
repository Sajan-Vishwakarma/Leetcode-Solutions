class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(int i:tasks) mp[i]++;
    
        int ans = 0;
        for(auto &[val,cnt]:mp){
            if(cnt < 2) return -1;
            if(cnt <= 3) ans++;
            else 
                ans += (cnt+2)/3;
        }
        return ans;
    }
};