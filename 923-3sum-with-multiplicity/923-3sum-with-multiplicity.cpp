#define MOD 1000000007
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int n = arr.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        vector<pair<int,int>> vec;
        for(auto &x:mp){
            vec.push_back({x.first,x.second});
        }
        
        long long ans = 0;
        for(int i=0;i<vec.size();i++){
            int t = target - vec[i].first;
            int j = i, k = vec.size()-1, cntfirst = vec[i].second;
            while( j <= k){
                int second = vec[j].first, third = vec[k].first;
                int cntsecond = vec[j].second,cntthird = vec[k].second;
                
                if( second + third < t){
                    j++;
                }
                else if(second + third > t){
                    k--;
                }
                else {
                    if( i < j && j < k){
                        ans += cntsecond*cntthird*cntfirst;
                    }
                    else if(i==j && j < k){
                        ans += ((cntfirst*(cntfirst-1))/2)*cntthird;
                    }
                    else if( i < j && j == k){
                        ans += (cntfirst*((cntsecond*(cntsecond-1))/2));
                    }
                    else { // i = j = k
                        ans += (cntfirst*1LL*(cntfirst-1)*(cntfirst-2))/6;
                    }
                    ans %= MOD;
                    j++;
                    k--;
                }
            }
        }
        
        return (int)ans%MOD;
    }
};