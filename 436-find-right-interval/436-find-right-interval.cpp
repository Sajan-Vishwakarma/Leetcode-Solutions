class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        map<int, int> vec;
        int n = intervals.size();
        
        for(int i=0;i<n;i++){
            vec[intervals[i][0]] = i;
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int l = intervals[i][0], r = intervals[i][1];
            auto it = vec.lower_bound(r);
            ans[i] = (it == vec.end())? -1: it->second;
        }

        return ans;
    }
};
