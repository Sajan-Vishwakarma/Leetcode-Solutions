#define ff first
#define ss second
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        vector<int> v;
        int n = grid.size(), m = grid[0].size(), total = n*m;
        k %= total;
        
        auto index=[&](int val)->pair<int,int>{
            val += (total);
            val %= (total);
            int i = val/m, j = val%m;
            return {i,j};
        };

        for(int p1=total-k;p1 < total;p1++){
            pair<int,int> ij = index(p1);
            v.push_back(grid[ij.ff][ij.ss]);
        } 

        for(int p1=total-1;p1>=0;p1--){
            pair<int,int> fi = index(p1);
            if(p1 >= k){
                int p2=p1-k;
                pair<int,int> se = index(p2);
                grid[fi.ff][fi.ss] = grid[se.ff][se.ss];
            }
            else{
                grid[fi.ff][fi.ss] = v.back();
                v.pop_back();
            }
        }
        return grid;
    }
};