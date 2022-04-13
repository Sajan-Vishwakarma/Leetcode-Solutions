class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        
        int n = d.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            auto it  = mp.find(p[i]);
            if( it == mp.end()){
                mp[p[i]] = d[i];
            }
            else{
                it->second = min(it->second,d[i]);
            }
        }

        sort(w.begin(), w.end());
        int last = w.size(), ans = 0;
        for(auto it = mp.rbegin(); it != mp.rend();it++){
            int profit = it->first, difficulty = it->second;
            auto index = lower_bound(w.begin(), w.end(),difficulty) - w.begin();
            if( index >= last) continue;
            ans += (last-index)*profit;
            last = index;
        }

        return ans;
    }
};