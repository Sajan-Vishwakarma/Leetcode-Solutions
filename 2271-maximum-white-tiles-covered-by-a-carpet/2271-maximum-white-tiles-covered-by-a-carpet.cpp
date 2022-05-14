class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {

        sort(tiles.begin(), tiles.end());

        vector<int> v;
        v.push_back(tiles[0][0]);
        v.push_back(tiles[0][1]);

        for(int i=1;i<tiles.size();i++){
            int b = v.back(); v.pop_back();
            int a = v.back(); v.pop_back();
            int c = tiles[i][0], d = tiles[i][1];

            if( c <= b || abs(c-b) ==1){
                v.push_back({min(a,c)});
                v.push_back({max(b,d)});
            }
            else{
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                v.push_back(d);
            }
        }

        int n = v.size();
        vector<int> pref(n,0);
        for(int i=2;i<n;i+=2){
            pref[i] = v[i]-v[i-1]-1;
        }
        for(int i=1;i<n;i++){
            pref[i] += pref[i-1];
        }

        if( carpetLen >= v[n-1]-v[0]){
            return v[n-1]-v[0]+1-pref[n-1]-pref[0];
        }

        // dbg(v,pref);

        int ans =0;
        for(int i=0;i<n;i+=2){
            int l = v[i], r = v[i]+carpetLen-1;
            auto it = prev(upper_bound(v.begin(),v.end(),r));

            int index = it-v.begin();
            int range = v[index]-v[i]+1;
            if(index%2 == 0){
                range += (r-v[index]);
            }
            int gap = pref[index]-pref[i];
                
            // dbg(i,l,r,index,v[i],v[index],range,gap);
            ans = max(ans, range-gap);
        }

        return ans;
    }
};