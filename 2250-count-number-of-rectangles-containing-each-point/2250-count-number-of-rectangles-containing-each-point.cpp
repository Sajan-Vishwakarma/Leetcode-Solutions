class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {

        vector<int> mp[101];
        for(auto &rectangle:rectangles){
            int li = rectangle[0], hi = rectangle[1];
            mp[hi].push_back(li);
        }
        
        for(auto &v:mp){
            sort(v.begin(),v.end());
        }

        vector<int> ans;
        for(auto &point:points){
            int x= point[0], y = point[1];
            int count = 0;
            for(int h=y;h<=100;h++){
                count += mp[h].end() - lower_bound(mp[h].begin(), mp[h].end(),x);
            }
            ans.push_back(count);
        }
        return ans;
    }
};