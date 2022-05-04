class Solution {
public:
    using vvi = vector<vector<int>>;
    using vvvi = vector<vector<vector<int>>>;

    int fun(int r1,int c1,int c2,int N,vvi &garden,vvvi &memo){

        int r2 = r1+c1-c2;

        // handling walks going out of bound and garden cell having thorns
        if(N == r1 || N == r2 || N == c1 || N == c2 || garden[r1][c1] == -1 || garden[r2][c2] == -1)
            return -1e5;

        if( r1==N-1 && c1 == N-1)
            return garden[r1][c1];

        if(memo[r1][c1][c2] != INT_MIN){
            return memo[r1][c1][c2];
        }

        int ans = garden[r1][c1];
        if(c1 != c2) ans += garden[r2][c2];


	    ans += max({ fun(r1+1,c1,c2,N,garden,memo), // both down
			fun(r1+1,c1,c2+1,N,garden,memo), // walk1 down walk2 right
			fun(r1,c1+1,c2,N,garden,memo), // walk1 right walk2 down
			fun(r1,c1+1,c2+1,N,garden,memo) // both right
			 });

        return memo[r1][c1][c2] = ans;
    }

    int cherryPickup(vector<vector<int>>& garden) {
        int n= garden.size();
        vector<vector<vector<int>>> memo(n,vector<vector<int>>(n,vector<int>(n,INT_MIN)));
        return max(0, fun(0,0,0,n,garden,memo));
    }
};