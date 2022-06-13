class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        vector<pair<int,int>> row[n], col[m];

        for(vector<int> &guard:guards){
            int x = guard[0], y = guard[1];
            row[x].push_back({y,0});
            col[y].push_back({x,0});
        }
        for(vector<int> &wall:walls){
            int x = wall[0], y = wall[1];
            row[x].push_back({y,1});
            col[y].push_back({x,1});
        }

        for(int i=0;i<n;i++){
            sort(row[i].begin(), row[i].end());
        }
        for(int i=0;i<m;i++){
            sort(col[i].begin(), col[i].end());
        }

        auto leftright=[&](int x,int y){
            if( row[x].empty() ) // doesn't contain any guard or walls; 
                return false;

            auto right = lower_bound(row[x].begin(), row[x].end(),pair<int,int>{y,-1});

            if( right != row[x].end() ){            
                int fyr = right->first, egwr = right->second; 
                if(fyr == y) return false;
                if(egwr == 0) return true;
            }

            if( right != begin(row[x]) ){
                auto left = prev(right);
                int fyl = left->first, egwl = left->second;
                if( egwl == 0) return true;
            }
            return false;
        };

        auto updown=[&](int x,int y){
            if(col[y].empty()) 
                return false;

            auto down = lower_bound(col[y].begin(), col[y].end(),pair<int,int>{x,-1});

            if(down != col[y].end()){            
                int fxd = down->first, egwd = down->second;
                if( fxd == x) return false;
                if( egwd == 0 ) return true;
            }

            if( down != begin(col[y]) ){
                auto up = prev(down);
                int fxu = up->first, egwu = up->second;
                if( egwu == 0) return true;
            }
            return false;
        };

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( leftright(i,j) || updown(i,j) ){
                    // dbg(i,j);
                    ans++;
                }
            }
        }

        return n*m - walls.size() - guards.size() - ans;
    }
};