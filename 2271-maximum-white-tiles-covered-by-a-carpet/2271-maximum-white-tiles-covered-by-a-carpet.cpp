class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {

        sort(tiles.begin(), tiles.end());

        vector<int> v;
        for(auto &vec:tiles){
            v.push_back(vec[0]);
            v.push_back(vec[1]);
        }
        
        int n = v.size();
        vector<int> pref(n,0);
        for(int i=2;i<n;i+=2){
            pref[i] = v[i]-v[i-1]-1;
        }
        for(int i=1;i<n;i++){
            pref[i] += pref[i-1];
        }

        int ans =0;
        for(int i=0;i<n;i+=2){
            int l = v[i], r = v[i]+carpetLen-1;
            auto it = prev(upper_bound(v.begin(),v.end(),r));

            int index = it-v.begin();
            int cover = v[index]-v[i]+1;
            if(index%2 == 0){
                cover += (r-v[index]);
            }
            int gap = pref[index]-pref[i];
            ans = max(ans, cover-gap);
        }

        return ans;
    }
};