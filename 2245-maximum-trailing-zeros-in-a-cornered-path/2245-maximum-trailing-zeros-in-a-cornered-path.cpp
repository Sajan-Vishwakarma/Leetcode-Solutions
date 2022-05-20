// operator overloading
array<int,2> operator+(const array<int,2> &l,const array<int,2> &r){
    return array<int,2>{l[0]+r[0],l[1]+r[1]};
}

array<int,2> operator-(const array<int,2> &l,const array<int,2> &r){
    return array<int,2>{l[0]-r[0],l[1]-r[1]};
}

class Solution {
public:
    bool ok = false;
    vector<array<int,2>> factors;

    Solution(){
        if(ok) return;

        auto count = [&](int num)->array<int,2>{
            int f5 = 0,f2 = 0;
            while(num%2 == 0){
                f2++;num/=2;
            } 
            for(int i=3;i*i<=num;i+=2){
                while(num%i == 0){
                    f5 += (i == 5);num/=i;
                } 
            }
            if(num >= 2){
                f2 += (num == 2);
                f5 += (num == 5);
            } 
            return array<int,2>{f2,f5};
        };

        factors.push_back({0,0});
        for(int num=1;num <= 1000;num++){
            factors.push_back(count(num));
        }
        ok = true;
    }
    
    int maxTrailingZeros(vector<vector<int>>& grid) {

        using vva2 = vector<vector<array<int,2>>>;
        using va2 = vector<array<int,2>>;

        int n = grid.size(), m = grid[0].size();
        vva2 pref(n,va2(m)), down(n,va2(m));


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pref[i][j] = factors[grid[i][j]];
                if( j > 0 ) pref[i][j] = pref[i][j] + pref[i][j-1];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                down[i][j] = factors[grid[i][j]];
                if(i > 0 ) down[i][j] = down[i][j] + down[i-1][j];  
            }
        }

        auto pairs=[&](array<int,2> l){
            return min(l[0],l[1]);
        };

        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                array<int,2> curr = factors[grid[i][j]];
                array<int,2> left   = pref[i][j] - curr;
                array<int,2> right  = pref[i][m-1] - pref[i][j];
                array<int,2> top    = down[i][j];
                array<int,2> bottom = down[n-1][j] - down[i][j] + curr;

                ans = max({ans, pairs(top+left), pairs(top+right), 
                    pairs(bottom+left), pairs(bottom+right)});
            }
        }
        return ans;
    }
};